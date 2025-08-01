/*
 * If not stated otherwise in this file or this component's Licenses.txt file the
 * following copyright and licenses apply:
 *
 * Copyright 2015 RDK Management
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
*/

/**********************************************************************
   Copyright [2015] [Broadcom Corporation]
 
   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at
 
       http://www.apache.org/licenses/LICENSE-2.0
 
   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
**********************************************************************/

/**********************************************************************

    Module: dpoe_hal.h

        For CCSP Component: DPoE management
		
    ---------------------------------------------------------------

    Description:

        This header file gives the function call prototypes and 
        structure definitions used for the RDK-Broadband 
        DPoE hardware abstraction layer as per the DPoE-SP-OAMv1.0-I08-140807 
		specification.

        NOTE:
        THIS VERSION IS AN EARLY DRAFT INTENDED TO GET COMMENTS FROM COMCAST.
        TESTING HAS NOT YET BEEN COMPLETED.  
       
    ---------------------------------------------------------------

    Environment:
        This HAL layer is intended to support DPoE drivers 
        through an open API based on the 
		CableLabs Cable Data Services DOCSIS® Provisioning of EPON Specifications
        DPoE™ OAM Extensions Specification 

    ---------------------------------------------------------------
    HAL version:
        The version of the DPoE HAL is specified in #defines below.

    ---------------------------------------------------------------
    Author:
        John McQueen jmcqueen@broadcom.com		

**********************************************************************/
#include "dpoe_hal.h"

#define DPOE_MAC_ADDRESS_LENGTH 6

/*#include <linux/if.h>*/
/* if.h has conflict with types.h, manually define IFF_UP/RUNNING/IFF_DORMANT */
#define PON_IFF_UP          0x1             /* interface is up              */
#define PON_IFF_RUNNING     0x40            /* interface RFC2863 OPER_UP    */
#define PON_IFF_DORMANT     0x20000         /* driver signals dormant       */


/**********************************************************************************
   DPoE Subsystem level function prototypes 
**********************************************************************************/

/*** Function: dpoe_getOnuId
Description: The ONU ID is a non-volatile number that uniquely identifies a physical DPoE ONU. 
By definition, the DPoE ONU ID is the lowest (numerically smallest) MAC address among all 
MAC addresses associated with the TU interface port of a DPoE ONU. All logical links on a 
DPoE ONU report the same DPoE ONU ID, despite having different link MAC addresses (per [802.3]).
Reference: DPoE-SP-OAMv1.0-I08-140807 specification 
Context: ONU */
INT dpoe_getOnuId(dpoe_mac_address_t *pOnuId)
{
    return RETURN_OK;
}

/*** Function: dpoe_getFirmwareInfo
Description: This attribute represents the DPoE ONU firmware version. 
The version number uniquely identifies a particular version of the ONU firmware. 
Format is defined by the ONU vendor. DPoE Systems can compare this value for equality 
with a provisioned value for the currently correct firmware version. "Newer than" or 
"compatible with" comparisons depend on version number format and should not be 
performed with a simple comparison. The Boot Version can be used to populate the BOOTR 
field in the sysDescr MIB variable. The Application Version can be used to populate 
the SW_REV field in the sysDescr MIB variable (see [DPoE-SP-OSSIv1.0]). 
Version values 0x0000 and 0xFFFF are reserved, and indicate loads that 
are not installed or are not available.
Reference: DPoE-SP-OAMv1.0-I08-140807 specification 
Context: ONU */
INT dpoe_getFirmwareInfo(dpoe_firmware_info_t *pFirmwareInfo)
{
    return RETURN_OK;
}

/*** Function: dpoe_getEponChipInfo
Description: This attribute represents the type of EPON chip used on the DPoE ONU.
Reference: DPoE-SP-OAMv1.0-I08-140807 specification 
Context: ONU */
INT dpoe_getEponChipInfo(dpoe_epon_chip_info_t *pEponChipInfo)
{
    return RETURN_OK;
}

/*** Function: dpoe_getManufacturerInfo 
Description: This function will return information corresponding to multiple OAM messages.
- Date of Manufacture (D7/00 05)
- Manufacturer Info (D7/00 06)
- ONU Manufacturer Organization Name (D7/00 0E)
Date of Manufacture: The date the DPoE ONU was manufactured, encoded in Binary Coded Decimal 
(BCD) digits as YYYYMMDD. For example, June 24, 2010, would be represented as 20 10 06 24. 
Manufacturer Info: This attribute holds manufacturer-specific information that identifies this individual ONU. 
This attribute typically contains a serial number, and possibly other manufacturing information, 
such as lot numbers or component revisions. Format is defined by the ONU vendor. 
ONU Manufacturer Organization Name: This attribute represents the organization which manufactured the D-ONU. 
It is used to validate the manufacturer CVC during secure software download. 
The value must exactly match the subject organizationName value in the firmware manufacturer CVC. 
Reference: DPoE-SP-OAMv1.0-I08-140807 specification 
Context: ONU */
INT dpoe_getManufacturerInfo(dpoe_manufacturer_t *pManufacturerInfo)
{
    return RETURN_OK;
}

/*** Function: dpoe_getMaxLogicalLinks 
Description: The maximum number of logical links the ONU supports on the EPON.
Reference: DPoE-SP-OAMv1.0-I08-140807 specification 
Context: ONU */
USHORT dpoe_getMaxLogicalLinks(dpoe_onu_max_logical_links_t *pMaxLogicalLinks)
{
    return RETURN_OK;
}

/*** Function: dpoe_LlidForwardingStateGetEntryCount
Description: The maximum number of logical links the ONU supports on the EPON.
Reference: DPoE-SP-OAMv1.0-I08-140807 specification
Context: ONU */

INT dpoe_LlidForwardingStateGetEntryCount( USHORT *pNumEntry )
{
    return RETURN_OK;
}

/*** Function: dpoe_OamFrameRateGetEntryCount
Description: The maximum number of logical links the ONU supports on the EPON.
Reference: DPoE-SP-OAMv1.0-I08-140807 specification
Context: ONU */

INT dpoe_OamFrameRateGetEntryCount( USHORT *pNumEntry )
{
   return dpoe_LlidForwardingStateGetEntryCount(pNumEntry);
}

/*** Function: dpoe_OnuLinkStatisticsGetEntryCount
Description: The maximum number of logical links the ONU supports on the EPON.
Reference: DPoE-SP-OAMv1.0-I08-140807 specification
Context: ONU */

INT dpoe_OnuLinkStatisticsGetEntryCount( USHORT *pNumEntry )
{
   return dpoe_LlidForwardingStateGetEntryCount(pNumEntry);
}

/*** Function: dpoe_getNumberOfNetworkPorts 
Description: This attribute provides the total number of TU interface ports on the ONU.
Reference: DPoE-SP-OAMv1.0-I08-140807 specification 
Context: ONU */
INT dpoe_getNumberOfNetworkPorts(ULONG *pNumPorts)
{
    return RETURN_OK;
}

/*** Function: dpoe_getNumberOfS1Interfaces
Description: This attribute provides the number of S1 interfaces on the DPoE ONU.
Reference: DPoE-SP-OAMv1.0-I08-140807 specification 
Context: ONU */
INT dpoe_getNumberOfS1Interfaces(ULONG *pNumS1Interfaces)
{
    return RETURN_OK;
}

/*** Function: dpoe_getOnuPacketBufferCapabilities
Description: This message provides a means for the DPoE ONU to convey information about 
packet buffer capabilities to the DPoE System 
Reference: DPoE-SP-OAMv1.0-I08-140807 specification 
Context: ONU */
INT dpoe_getOnuPacketBufferCapabilities(dpoe_onu_packet_buffer_capabilities_t *pCapabilities)
{
    return RETURN_OK;
}

/*** Function: dpoe_getLlidForwardingState
Description: This attribute represents the current traffic state for an LLID. User data traffic 
may be enabled (normal operation) or disabled (discarded by the DPoE ONU). 
Only OAM and MPCP remain enabled regardless of the LLID forwarding state. 
Reference: DPoE-SP-OAMv1.0-I08-140807 specification 
Context: Logical Link */
INT dpoe_getLlidForwardingState(dpoe_link_forwarding_state_t linkForwardingState[], USHORT numEntries)
{
    return RETURN_OK;
}

/*** Function: dpoe_getOamFrameRate
Description: This attribute represents the maximum rate at which OAM PDUs are transmitted on a link. 
Setting the Maximum OAM Frame Rate to 0 disables rate control. 
The Minimum OAM Frame Rate is the heartbeat rate. This is the rate at which OAM PDUs are sent 
between the ONU and DPoE System, using an Info PDU as a "heartbeat" if there is no other OAM activity, 
as per [802.3]. The heartbeat rate is specified as one heartbeat PDU per specified time interval. 
The time interval is specified as the value provisioned in the message x 100ms. 
Therefore, setting the Minimum OAM Frame Rate to 10 specifies a rate of 1 PDU per 10 x 100ms. 
This equals 1 PDU per 1 second. The DPoE ONU implementation maintains one instance of the OAM rate. 
This rate applies to all links on the ONU. 
Reference: DPoE-SP-OAMv1.0-I08-140807 specification 
Context: Logical Link */
INT dpoe_getOamFrameRate(dpoe_link_oam_frame_rate_t linkOamFrameRate[], USHORT numEntries)
{
    return RETURN_OK;
}

/*** Function: dpoe_getDeviceSysDescrInfo
Description: This function will return multiple pieces of device system information.
Vendor Name: This attribute represents the ONU vendor name. 
It can be used to populate the VENDOR field in the sysDescr 
MIB variable (see [DPoE-SP-OSSIv1.0]), and may or may not be the same as the ONU 
Manufacturer Organization Name. Format of the vendor name is vendor specific. 
Model Number: This attribute represents the ONU model number.  
It can be used to populate the MODEL field in the sysDescr MIB variable (see [DPoE-SP-OSSIv1.0]). 
Format of the model number is vendor specific. The D-ONU SHOULD limit the model number length to less than 32 bytes.
HardwareInfo: This attribute represents the ONU hardware version.  
It can be used to populate the HW_REV field in the sysDescr MIB variable (see [DPoE-SP-OSSIv1.0]). 
Format of the hardware version information is vendor specific. 
The D-ONU SHOULD limit the vendor name, model number, and hardware version length to less than 32 bytes.
Reference: DPoE-SP-OAMv1.0-I08-140807 specification 
Context: ONU */
INT dpoe_getDeviceSysDescrInfo(dpoe_device_sys_descr_info_t *pDeviceSysDescrInfo)
{
    return RETURN_OK;
}

/*** Function: dpoe_getEponMode
Description: This attribute represents the EPON mode(s) supported by this ONU.
DPoE Systems that support 2G-EPON MUST support this attribute. DPoE ONUs that support 2G-EPON MUST
support this attribute. DPoE Systems that support 1G-EPON and 10G-EPON SHOULD support this attribute. DPoE
ONUs that support 1G-EPON and 10G-EPON SHOULD support this attribute.
Reference: DPoE-SP-OAMv1.0-I08-140807 specification ( see spec for intepretation of return value )
Context: ONU
*/
INT dpoe_getEponMode(USHORT *pMode)
{
    return RETURN_OK;
}

/*** Function: dpoe_setResetOnu
Description: This attribute resets the ONU, as if from power on.  
Reference: DPoE-SP-OAMv1.0-I08-140807 specification 
Context: ONU */
INT dpoe_setResetOnu(void)
{
    return RETURN_OK;
}

/*** Function: dpoe_getDynamicMacAddressAgeLimit
Description: This attribute represents Dynamic MAC learning table age limit.  
Reference: DPoE-SP-OAMv1.0-I08-140807 specification 
Context: ONU */
INT dpoe_getDynamicMacAddressAgeLimit(USHORT *pAgeLimit)
{
    return RETURN_OK;
}

/*** Function: dpoe_getDynamicMacLearningTableSize
Description: This attribute is a capability attribute that represents 
the maximum size of the DPoE ONU MAC address learning table for the 
entire DPoE ONU. 
The total number of MAC addresses learned by the DPoE ONU cannot exceed this number.  
Reference: DPoE-SP-OAMv1.0-I08-140807 specification 
Context: ONU */
INT dpoe_getDynamicMacLearningTableSize(USHORT *pNumEntries)
{
    return RETURN_OK;
}


/*** Function: dpoe_getDynamicMacTable
Description: This attribute represents the dynamically learned MAC address rules. 
entrty number starts with 0 -> pNumEntries-1
Reference: DPoE-SP-OAMv1.0-I08-140807 specification 
Context: Logical Link */
INT dpoe_getDynamicMacTable(dpoe_link_mac_address_t *pLinkDynamicMacTable, USHORT link)
{
     return RETURN_OK;
}

/*** Function: dpoe_getStaticMacTable
Description: This attribute represents the statically provisioned MAC address table 
Reference: DPoE-SP-OAMv1.0-I08-140807 specification 
Context: Logical Link*/

INT dpoe_getStaticMacTable(dpoe_link_mac_address_t *pLinkStaticMacTable, USHORT link)
{
    return RETURN_OK;
}


/*** Function: dpoe_getMacLearningAggregateLimit
Description: This message represents the aggregate dynamic MAC address limit
for the DPoE ONU as a whole. This is the maximum number of addresses
that can be learned by all ports combined.
Reference: DPoE-SP-OAMv1.0-I08-140807 specification
Context: ONU */
INT dpoe_getMacLearningAggregateLimit(USHORT *pAggregrateLimit)
{
    return RETURN_OK;
}


/*** Function: dpoe_getOnuStatistics
Description: This function will return a list of all LLID port traffic statistics
 for this ONU. 
 Inputs: pOnuTrafficStats - this pointer should allocate 'numEntries' times of
	dpoe_llid_traffic_stats_t size memory where 'numEntries' size is determined by
	dpoe_getMaxLogicalLinks(). 
Reference: DPoE-SP-OAMv1.0-I08-140807 specification 
Context: Logical Link 
Example Usage: 
dpoe_link_traffic_stats_t *pMyLinkStats = (dpoe_link_traffic_stats_t *)malloc((sizeof(dpoe_link_traffic_stats_t)*dpoe_getMaxLogicalLinks()));
memset((char *)pMyLinkStats, 0x00, (sizeof(dpoe_link_traffic_stats_t)*dpoe_getMaxLogicalLinks()));
dpoe_getOnuLinkStatistics(pMyLinkStats, dpoe_getMaxLogicalLinks());
*/
INT dpoe_getOnuLinkStatistics(dpoe_link_traffic_stats_t onuLinkTrafficStats[], USHORT numEntries)
{
    return RETURN_OK;
}

/*** Function: dpoe_getOnuStatistics
Description: This function will clear all statistics for the DPoE ONU.
Inputs: none
Reference: DPoE-SP-OAMv1.0-I08-140807 specification

Context: ONU
*/
INT dpoe_setClearOnuLinkStatistics(void)
{
    return RETURN_OK;
}


/*** Function: dpoe_hal_Reboot_Ready
Description: Get the Reboot Ready Status
Parameters:
ULONG *pValue- Values of 1 for Ready, 2 for Not Ready
@return the status of the operation.
@retval RETURN_OK if successful.
@retval RETURN_ERR if any error is detected
*/

#define MTA_END_POINT_NUM_OF_INSTANCES 2
INT dpoe_hal_Reboot_Ready(ULONG *pValue)
{
    BOOLEAN reboot_ready = TRUE;

    if(reboot_ready)
        *pValue = 1;
    else
        *pValue = 2;

    return RETURN_OK;
}


/*** Function: dpoe_hal_ReinitMac :
 Description: Reinit DPoE.  Performs reinit MAC only to same DS/US
 Parameters :
     None

 @return The status of the operation.
 @retval RETURN_OK if successful.
 @retval RETURN_ERR if any error is detected

 @execution Synchronous.
 @sideeffect None.

 @note This function must not suspend and must not invoke any blocking system
 calls. It should probably just send a message to a driver event handler task.
*/
INT dpoe_hal_ReinitMac()
{
    return RETURN_OK;
}


