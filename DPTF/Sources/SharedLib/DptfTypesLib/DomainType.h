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

#pragma once

#include "Dptf.h"
#include "esif_sdk_domain_type.h"

namespace DomainType
{
	enum Type
	{
		Invalid,
		Processor,
		Graphics,
		Memory,
		Temperature,
		Fan,
		Chipset,
		Ethernet,
		Wireless,
		Storage, // AHCI
		MultiFunction,
		Display,
		Charger, // BatteryCharger
		Battery,
		Audio,
		Other,
		WWan,
		WGig, // Deprecated
		Power,
		Thermistor,
		Infrared,
		WirelessRfem, // Deprecated
		Virtual,
		Ambient,
		DSx,
		Rfem,
		M2Cnv,
		SocCnv,
		IVCam,
		DgfxCore,
		DgfxMem,
		DgfxMcp,
		Cam2D,
		All,
		Max
	};

	std::string ToString(DomainType::Type type);
}

DomainType::Type EsifDomainTypeToDptfDomainType(esif_domain_type esifDomainType);
esif_domain_type DptfDomainTypeToEsifDomainType(DomainType::Type dptfDomainType);
