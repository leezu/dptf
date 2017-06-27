/*******************************************************************************
** This file is provided under a dual BSD/GPLv2 license.  When using or
** redistributing this file, you may do so under either license.
**
** GPL LICENSE SUMMARY
**
** Copyright (c) 2013-2017 Intel Corporation All Rights Reserved
**
** This program is free software; you can redistribute it and/or modify it under
** the terms of version 2 of the GNU General Public License as published by the
** Free Software Foundation.
**
** This program is distributed in the hope that it will be useful, but WITHOUT
** ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
** FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
** details.
**
** You should have received a copy of the GNU General Public License along with
** this program; if not, write to the Free Software  Foundation, Inc.,
** 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.
** The full GNU General Public License is included in this distribution in the
** file called LICENSE.GPL.
**
** BSD LICENSE
**
** Copyright (c) 2013-2017 Intel Corporation All Rights Reserved
**
** Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are met:
**
** * Redistributions of source code must retain the above copyright notice, this
**   list of conditions and the following disclaimer.
** * Redistributions in binary form must reproduce the above copyright notice,
**   this list of conditions and the following disclaimer in the documentation
**   and/or other materials provided with the distribution.
** * Neither the name of Intel Corporation nor the names of its contributors may
**   be used to endorse or promote products derived from this software without
**   specific prior written permission.
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
** AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
** IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
** ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
** LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  SPECIAL, EXEMPLARY, OR
** CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
** SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
** INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
** CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
** ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
** POSSIBILITY OF SUCH DAMAGE.
**
*******************************************************************************/

#pragma once

#include "esif_sdk.h"

/*
* Event Types
*/

/* Event Priority */
typedef enum esif_event_priority {
	ESIF_EVENT_PRIORITY_NORMAL = 0,
	ESIF_EVENT_PRIORITY_LOW = 1,
	ESIF_EVENT_PRIORITY_HIGH = 2,
} esif_event_priority_t;

/* Event Priority String */
static ESIF_INLINE char *
esif_event_priority_str(esif_event_priority_t priority)
{
	switch (priority) {
	ESIF_CASE_ENUM(ESIF_EVENT_PRIORITY_NORMAL);
	ESIF_CASE_ENUM(ESIF_EVENT_PRIORITY_LOW);
	ESIF_CASE_ENUM(ESIF_EVENT_PRIORITY_HIGH);
	}
	return ESIF_NOT_AVAILABLE;
}


/* Event Type */
typedef enum esif_event_type {
	ESIF_EVENT_APP_CONNECTED_STANDBY_ENTRY = 0,
	ESIF_EVENT_APP_CONNECTED_STANDBY_EXIT = 1,
	ESIF_EVENT_APP_ACTIVE_RELATIONSHIP_CHANGED = 2,
	ESIF_EVENT_APP_THERMAL_RELATIONSHIP_CHANGED = 3,
	ESIF_EVENT_APP_FOREGROUND_CHANGED = 4,
	ESIF_EVENT_PARTICIPANT_SUSPEND = 5,
	ESIF_EVENT_PARTICIPANT_RESUME = 6,
	ESIF_EVENT_DOMAIN_CTDP_CAPABILITY_CHANGED = 7,
	ESIF_EVENT_DOMAIN_CORE_CAPABILITY_CHANGED = 8,
	ESIF_EVENT_DOMAIN_DISPLAY_CAPABILITY_CHANGED = 9,
	ESIF_EVENT_DOMAIN_DISPLAY_STATUS_CHANGED = 10,
	ESIF_EVENT_DOMAIN_PERF_CAPABILITY_CHANGED = 11,
	ESIF_EVENT_DOMAIN_PERF_CONTROL_CHANGED = 12,
	ESIF_EVENT_DOMAIN_POWER_CAPABILITY_CHANGED = 13,
	ESIF_EVENT_DOMAIN_POWER_THRESHOLD_CROSSED = 14,
	ESIF_EVENT_DOMAIN_PRIORITY_CHANGED = 15,
	ESIF_EVENT_DOMAIN_TEMP_THRESHOLD_CROSSED = 16,
	ESIF_EVENT_PARTICIPANT_SPEC_INFO_CHANGED = 17,
	ESIF_EVENT_PARTICIPANT_CREATE = 18,
	ESIF_EVENT_PARTICIPANT_UNREGISTER = 19,
	ESIF_EVENT_PARTICIPANT_SHUTDOWN = 20,
	ESIF_EVENT_ACPI = 21,
	ESIF_EVENT_PASSIVE_TABLE_CHANGED = 24,
	ESIF_EVENT_DISPLAY_ORIENTATION_CHANGED = 26,
	ESIF_EVENT_DEVICE_ORIENTATION_CHANGED = 27,
	ESIF_EVENT_MOTION_CHANGED = 28,
	ESIF_EVENT_SYSTEM_COOLING_POLICY_CHANGED = 29,
	ESIF_EVENT_OS_CTDP_CAPABILITY_CHANGED = 31,
	ESIF_EVENT_RF_PROFILE_CHANGED = 32,
	ESIF_EVENT_RF_CONNECTION_STATUS_CHANGED = 33,
	ESIF_EVENT_LOG_VERBOSITY_CHANGED = 34,
	ESIF_EVENT_POWER_SOURCE_CHANGED = 37,
	ESIF_EVENT_TEMP_THRESHOLD_INTERRUPT = 39,
	ESIF_EVENT_DRIVER_SUSPEND = 40,
	ESIF_EVENT_DRIVER_RESUME = 41,
	ESIF_EVENT_ADAPTIVE_PERFORMANCE_CONDITIONS_TABLE_CHANGED = 42,
	ESIF_EVENT_ADAPTIVE_PERFORMANCE_ACTIONS_TABLE_CHANGED = 43,
	ESIF_EVENT_OS_POWER_SOURCE_CHANGED = 44,
	ESIF_EVENT_OS_LID_STATE_CHANGED = 45,
	ESIF_EVENT_OS_BATTERY_PERCENT_CHANGED = 46,
	ESIF_EVENT_OS_PLATFORM_TYPE_CHANGED = 47,
	ESIF_EVENT_OS_DOCK_MODE_CHANGED = 48,
	ESIF_EVENT_OEM_VARS_CHANGED = 49,
	ESIF_EVENT_VIRTUAL_SENSOR_CALIB_TABLE_CHANGED = 50,
	ESIF_EVENT_VIRTUAL_SENSOR_POLLING_TABLE_CHANGED = 51,
	ESIF_EVENT_VIRTUAL_SENSOR_RECALC_CHANGED = 52,
	ESIF_EVENT_BATTERY_STATUS_CHANGED = 54,
	ESIF_EVENT_BATTERY_INFORMATION_CHANGED = 55,
	ESIF_EVENT_PLATFORM_BATTERY_STEADY_STATE_CHANGED = 56,
	ESIF_EVENT_PLATFORM_POWER_SOURCE_CHANGED = 57,
	ESIF_EVENT_CHARGER_TYPE_CHANGED = 59,
	ESIF_EVENT_PLATFORM_REST_OF_POWER_CHANGED = 60,
	ESIF_EVENT_POWER_BOSS_CONDITIONS_TABLE_CHANGED = 63,
	ESIF_EVENT_POWER_BOSS_ACTIONS_TABLE_CHANGED = 64,
	ESIF_EVENT_DPTF_POLICY_LOADED_UNLOADED = 65,
	ESIF_EVENT_DPTF_POLICY_ACTIVITY_LOGGING_ENABLED = 66,
	ESIF_EVENT_DPTF_POLICY_ACTIVITY_LOGGING_DISABLED = 67,
	ESIF_EVENT_DPTF_PARTICIPANT_ACTIVITY_LOGGING_ENABLED = 68,
	ESIF_EVENT_DPTF_PARTICIPANT_ACTIVITY_LOGGING_DISABLED = 69,
	ESIF_EVENT_DPTF_PARTICIPANT_CONTROL_ACTION = 70,
	ESIF_EVENT_MAX_BATTERY_POWER_CHANGED = 71,
	ESIF_EVENT_OS_POWERSCHEME_PERSONALITY_CHANGED = 72,
	ESIF_EVENT_OS_MOBILE_NOTIFICATION = 73,
	ESIF_EVENT_EMERGENCY_CALL_MODE_TABLE_CHANGED = 74,
	ESIF_EVENT_APP_LOADED = 75,
	ESIF_EVENT_APP_UNLOADED = 76,
	ESIF_EVENT_ADAPTIVE_PERFORMANCE_PARTICIPANT_CONDITION_TABLE_CHANGED = 77,
	ESIF_EVENT_ACTION_LOADED = 78,
	ESIF_EVENT_ACTION_UNLOADED = 79,
	ESIF_EVENT_PID_ALGORITHM_TABLE_CHANGED = 80,
	ESIF_EVENT_POWER_BOSS_MATH_TABLE_CHANGED = 81,
	ESIF_EVENT_APP_UNLOADING = 82,
	ESIF_EVENT_ACTIVE_CONTROL_POINT_RELATIONSHIP_TABLE_CHANGED = 83,
	ESIF_EVENT_PARTICIPANT_UNREGISTER_COMPLETE = 84,
	ESIF_EVENT_SUPPORTED_POLICIES_CHANGED = 85,
	ESIF_EVENT_LF_UNLOADED = 86,
	ESIF_EVENT_DOMAIN_ENERGY_THRESHOLD_CROSSED = 91,
	ESIF_EVENT_POWER_SHARING_ALGORITHM_TABLE_CHANGED = 92,
	ESIF_EVENT_WORKLOAD_HINT_CONFIGURATION_CHANGED = 93,
} esif_event_type_t;

/* Max Enum Value for Iteration purposes */
#define MAX_ESIF_EVENT_ENUM_VALUE  ESIF_EVENT_WORKLOAD_HINT_CONFIGURATION_CHANGED

/* Event Type String */
static ESIF_INLINE char *esif_event_type_str(esif_event_type_t type)
{
	switch (type) {
	ESIF_CASE_ENUM(ESIF_EVENT_APP_CONNECTED_STANDBY_ENTRY);
	ESIF_CASE_ENUM(ESIF_EVENT_APP_CONNECTED_STANDBY_EXIT);
	ESIF_CASE_ENUM(ESIF_EVENT_APP_ACTIVE_RELATIONSHIP_CHANGED);
	ESIF_CASE_ENUM(ESIF_EVENT_APP_THERMAL_RELATIONSHIP_CHANGED);
	ESIF_CASE_ENUM(ESIF_EVENT_APP_FOREGROUND_CHANGED);
	ESIF_CASE_ENUM(ESIF_EVENT_PARTICIPANT_SUSPEND);
	ESIF_CASE_ENUM(ESIF_EVENT_PARTICIPANT_RESUME);
	ESIF_CASE_ENUM(ESIF_EVENT_DOMAIN_CTDP_CAPABILITY_CHANGED);
	ESIF_CASE_ENUM(ESIF_EVENT_DOMAIN_CORE_CAPABILITY_CHANGED);
	ESIF_CASE_ENUM(ESIF_EVENT_DOMAIN_DISPLAY_CAPABILITY_CHANGED);
	ESIF_CASE_ENUM(ESIF_EVENT_DOMAIN_DISPLAY_STATUS_CHANGED);
	ESIF_CASE_ENUM(ESIF_EVENT_DOMAIN_PERF_CAPABILITY_CHANGED);
	ESIF_CASE_ENUM(ESIF_EVENT_DOMAIN_PERF_CONTROL_CHANGED);
	ESIF_CASE_ENUM(ESIF_EVENT_DOMAIN_POWER_CAPABILITY_CHANGED);
	ESIF_CASE_ENUM(ESIF_EVENT_DOMAIN_POWER_THRESHOLD_CROSSED);
	ESIF_CASE_ENUM(ESIF_EVENT_DOMAIN_PRIORITY_CHANGED);
	ESIF_CASE_ENUM(ESIF_EVENT_DOMAIN_TEMP_THRESHOLD_CROSSED);
	ESIF_CASE_ENUM(ESIF_EVENT_PARTICIPANT_SPEC_INFO_CHANGED);
	ESIF_CASE_ENUM(ESIF_EVENT_PARTICIPANT_CREATE);
	ESIF_CASE_ENUM(ESIF_EVENT_PARTICIPANT_UNREGISTER);
	ESIF_CASE_ENUM(ESIF_EVENT_PARTICIPANT_SHUTDOWN);
	ESIF_CASE_ENUM(ESIF_EVENT_ACPI);
	ESIF_CASE_ENUM(ESIF_EVENT_PASSIVE_TABLE_CHANGED);
	ESIF_CASE_ENUM(ESIF_EVENT_DISPLAY_ORIENTATION_CHANGED);
	ESIF_CASE_ENUM(ESIF_EVENT_DEVICE_ORIENTATION_CHANGED);
	ESIF_CASE_ENUM(ESIF_EVENT_MOTION_CHANGED);
	ESIF_CASE_ENUM(ESIF_EVENT_SYSTEM_COOLING_POLICY_CHANGED);
	ESIF_CASE_ENUM(ESIF_EVENT_OS_CTDP_CAPABILITY_CHANGED);
	ESIF_CASE_ENUM(ESIF_EVENT_RF_PROFILE_CHANGED);
	ESIF_CASE_ENUM(ESIF_EVENT_RF_CONNECTION_STATUS_CHANGED);
	ESIF_CASE_ENUM(ESIF_EVENT_LOG_VERBOSITY_CHANGED);
	ESIF_CASE_ENUM(ESIF_EVENT_POWER_SOURCE_CHANGED);
	ESIF_CASE_ENUM(ESIF_EVENT_TEMP_THRESHOLD_INTERRUPT);
	ESIF_CASE_ENUM(ESIF_EVENT_DRIVER_SUSPEND);
	ESIF_CASE_ENUM(ESIF_EVENT_DRIVER_RESUME);
	ESIF_CASE_ENUM(ESIF_EVENT_ADAPTIVE_PERFORMANCE_CONDITIONS_TABLE_CHANGED);
	ESIF_CASE_ENUM(ESIF_EVENT_ADAPTIVE_PERFORMANCE_ACTIONS_TABLE_CHANGED);
	ESIF_CASE_ENUM(ESIF_EVENT_OS_POWER_SOURCE_CHANGED);
	ESIF_CASE_ENUM(ESIF_EVENT_OS_LID_STATE_CHANGED);
	ESIF_CASE_ENUM(ESIF_EVENT_OS_BATTERY_PERCENT_CHANGED);
	ESIF_CASE_ENUM(ESIF_EVENT_OS_PLATFORM_TYPE_CHANGED);
	ESIF_CASE_ENUM(ESIF_EVENT_OS_DOCK_MODE_CHANGED);
	ESIF_CASE_ENUM(ESIF_EVENT_OEM_VARS_CHANGED);
	ESIF_CASE_ENUM(ESIF_EVENT_VIRTUAL_SENSOR_CALIB_TABLE_CHANGED);
	ESIF_CASE_ENUM(ESIF_EVENT_VIRTUAL_SENSOR_POLLING_TABLE_CHANGED);
	ESIF_CASE_ENUM(ESIF_EVENT_VIRTUAL_SENSOR_RECALC_CHANGED);
	ESIF_CASE_ENUM(ESIF_EVENT_BATTERY_STATUS_CHANGED);
	ESIF_CASE_ENUM(ESIF_EVENT_BATTERY_INFORMATION_CHANGED);
	ESIF_CASE_ENUM(ESIF_EVENT_PLATFORM_BATTERY_STEADY_STATE_CHANGED);
	ESIF_CASE_ENUM(ESIF_EVENT_PLATFORM_POWER_SOURCE_CHANGED);
	ESIF_CASE_ENUM(ESIF_EVENT_CHARGER_TYPE_CHANGED);
	ESIF_CASE_ENUM(ESIF_EVENT_PLATFORM_REST_OF_POWER_CHANGED);
	ESIF_CASE_ENUM(ESIF_EVENT_POWER_BOSS_CONDITIONS_TABLE_CHANGED);
	ESIF_CASE_ENUM(ESIF_EVENT_POWER_BOSS_ACTIONS_TABLE_CHANGED);
	ESIF_CASE_ENUM(ESIF_EVENT_DPTF_POLICY_LOADED_UNLOADED);
	ESIF_CASE_ENUM(ESIF_EVENT_DPTF_POLICY_ACTIVITY_LOGGING_ENABLED);
	ESIF_CASE_ENUM(ESIF_EVENT_DPTF_POLICY_ACTIVITY_LOGGING_DISABLED);
	ESIF_CASE_ENUM(ESIF_EVENT_DPTF_PARTICIPANT_ACTIVITY_LOGGING_ENABLED);
	ESIF_CASE_ENUM(ESIF_EVENT_DPTF_PARTICIPANT_ACTIVITY_LOGGING_DISABLED);
	ESIF_CASE_ENUM(ESIF_EVENT_DPTF_PARTICIPANT_CONTROL_ACTION);
	ESIF_CASE_ENUM(ESIF_EVENT_MAX_BATTERY_POWER_CHANGED);
	ESIF_CASE_ENUM(ESIF_EVENT_OS_POWERSCHEME_PERSONALITY_CHANGED);
	ESIF_CASE_ENUM(ESIF_EVENT_OS_MOBILE_NOTIFICATION);
	ESIF_CASE_ENUM(ESIF_EVENT_EMERGENCY_CALL_MODE_TABLE_CHANGED);
	ESIF_CASE_ENUM(ESIF_EVENT_APP_LOADED);
	ESIF_CASE_ENUM(ESIF_EVENT_APP_UNLOADED);
	ESIF_CASE_ENUM(ESIF_EVENT_ADAPTIVE_PERFORMANCE_PARTICIPANT_CONDITION_TABLE_CHANGED);
	ESIF_CASE_ENUM(ESIF_EVENT_ACTION_LOADED);
	ESIF_CASE_ENUM(ESIF_EVENT_ACTION_UNLOADED);
	ESIF_CASE_ENUM(ESIF_EVENT_PID_ALGORITHM_TABLE_CHANGED);
	ESIF_CASE_ENUM(ESIF_EVENT_POWER_BOSS_MATH_TABLE_CHANGED);
	ESIF_CASE_ENUM(ESIF_EVENT_APP_UNLOADING);
	ESIF_CASE_ENUM(ESIF_EVENT_ACTIVE_CONTROL_POINT_RELATIONSHIP_TABLE_CHANGED);
	ESIF_CASE_ENUM(ESIF_EVENT_PARTICIPANT_UNREGISTER_COMPLETE);
	ESIF_CASE_ENUM(ESIF_EVENT_SUPPORTED_POLICIES_CHANGED);
	ESIF_CASE_ENUM(ESIF_EVENT_LF_UNLOADED);
	ESIF_CASE_ENUM(ESIF_EVENT_DOMAIN_ENERGY_THRESHOLD_CROSSED);
	ESIF_CASE_ENUM(ESIF_EVENT_POWER_SHARING_ALGORITHM_TABLE_CHANGED);
	ESIF_CASE_ENUM(ESIF_EVENT_WORKLOAD_HINT_CONFIGURATION_CHANGED);
	}
	return ESIF_NOT_AVAILABLE;
}
