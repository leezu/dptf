/******************************************************************************
** Copyright (c) 2013-2017 Intel Corporation All Rights Reserved
**
** Licensed under the Apache License, Version 2.0 (the "License"); you may not
** use this file except in compliance with the License.
**
** You may obtain a copy of the License at
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
** WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
**
** See the License for the specific language governing permissions and
** limitations under the License.
**
******************************************************************************/

#include "ActiveCoolingControl.h"
#include "StatusFormat.h"
using namespace std;
using namespace StatusFormat;

ActiveCoolingControl::ActiveCoolingControl(
	UIntN participantIndex,
	UIntN domainIndex,
	const DomainProperties& domainProperties,
	const ParticipantProperties& participantProperties,
	const PolicyServicesInterfaceContainer& policyServices)
	: m_policyServices(policyServices)
	, m_domainProperties(domainProperties)
	, m_participantProperties(participantProperties)
	, m_participantIndex(participantIndex)
	, m_domainIndex(domainIndex)
	, m_staticCaps(participantIndex, domainIndex, domainProperties, policyServices)
	, m_dynamicCaps(participantIndex, domainIndex, domainProperties, policyServices)
	, m_lastFanSpeedRequest(Percentage::createInvalid())
{
}

ActiveCoolingControl::~ActiveCoolingControl(void)
{
}

Bool ActiveCoolingControl::supportsActiveCoolingControls()
{
	return m_domainProperties.implementsActiveControlInterface();
}

Bool ActiveCoolingControl::supportsFineGrainControl()
{
	if (supportsActiveCoolingControls())
	{
		return m_staticCaps.getCapabilities().supportsFineGrainedControl();
	}
	return false;
}

void ActiveCoolingControl::requestFanSpeedPercentage(UIntN requestorIndex, const Percentage& fanSpeed)
{
	if (supportsFineGrainControl())
	{
		updateFanSpeedRequestTable(requestorIndex, snapToCapabilitiesBounds(fanSpeed));
		Percentage highestFanSpeed = chooseHighestFanSpeedRequest();
		if ((m_lastFanSpeedRequest.isValid() == false) || (highestFanSpeed != m_lastFanSpeedRequest))
		{
			m_policyServices.domainActiveControl->setActiveControl(m_participantIndex, m_domainIndex, highestFanSpeed);
			m_lastFanSpeedRequest = highestFanSpeed;
		}
	}
}

void ActiveCoolingControl::updateFanSpeedRequestTable(UIntN requestorIndex, const Percentage& fanSpeed)
{
	if (m_fanSpeedRequestTable.count(requestorIndex))
	{
		m_fanSpeedRequestTable.at(requestorIndex) = fanSpeed;
	}
	else
	{
		m_fanSpeedRequestTable.insert(pair<UIntN, Percentage>(requestorIndex, fanSpeed));
	}
}

Percentage ActiveCoolingControl::chooseHighestFanSpeedRequest()
{
	Percentage highestFanSpeed = getDynamicCapabilities().getMinFanSpeed();
	for (auto request = m_fanSpeedRequestTable.begin(); request != m_fanSpeedRequestTable.end(); request++)
	{
		if (request->second > highestFanSpeed)
		{
			highestFanSpeed = request->second;
		}
	}
	return highestFanSpeed;
}

void ActiveCoolingControl::forceFanOff(void)
{
	if (supportsActiveCoolingControls() && supportsFineGrainControl())
	{
		Percentage minFanSpeed = getDynamicCapabilities().getMinFanSpeed();
		m_policyServices.domainActiveControl->setActiveControl(m_participantIndex, m_domainIndex, minFanSpeed);
		m_lastFanSpeedRequest = minFanSpeed;
	}
}

std::shared_ptr<XmlNode> ActiveCoolingControl::getXml()
{
	auto status = XmlNode::createWrapperElement("active_cooling_control");
	status->addChild(XmlNode::createDataElement("participant_index", friendlyValue(m_participantIndex)));
	status->addChild(XmlNode::createDataElement("domain_index", friendlyValue(m_domainIndex)));
	status->addChild(XmlNode::createDataElement("name", m_participantProperties.getAcpiInfo().getAcpiScope()));
	if (supportsFineGrainControl())
	{
		status->addChild(XmlNode::createDataElement("speed", chooseHighestFanSpeedRequest().toString()));
	}
	status->addChild(XmlNode::createDataElement("fine_grain", friendlyValue(supportsFineGrainControl())));
	return status;
}

void ActiveCoolingControl::setControl(Percentage activeCoolingControlFanSpeed)
{
	if (supportsActiveCoolingControls())
	{
		m_policyServices.domainActiveControl->setActiveControl(
			m_participantIndex, m_domainIndex, activeCoolingControlFanSpeed);
	}
	else
	{
		throw dptf_exception("Domain does not support the active control fan interface.");
	}
}

void ActiveCoolingControl::refreshCapabilities()
{
	m_staticCaps.refresh();
	m_dynamicCaps.refresh();
}

const ActiveControlStaticCaps& ActiveCoolingControl::getCapabilities()
{
	return m_staticCaps.getCapabilities();
}

const ActiveControlDynamicCaps& ActiveCoolingControl::getDynamicCapabilities()
{
	return m_dynamicCaps.getCapabilities();
}

ActiveControlStatus ActiveCoolingControl::getStatus()
{
	if (supportsActiveCoolingControls())
	{
		return m_policyServices.domainActiveControl->getActiveControlStatus(m_participantIndex, m_domainIndex);
	}
	else
	{
		throw dptf_exception("Domain does not support the display control interface.");
	}
}

UIntN ActiveCoolingControl::getSmallestNonZeroFanSpeed()
{
	return m_policyServices.domainActiveControl->getActiveControlSet(m_participantIndex, m_domainIndex)
		.getSmallestNonZeroFanSpeed();
}

Bool ActiveCoolingControl::hasValidActiveControlSet()
{
	// active control set is empty or has only one entry of value 0
	if (((m_policyServices.domainActiveControl->getActiveControlSet(m_participantIndex, m_domainIndex).getCount()) == 0)
		|| (getSmallestNonZeroFanSpeed() == 0))
	{
		return false;
	}
	return true;
}