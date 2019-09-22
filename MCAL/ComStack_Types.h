#ifndef __COMSTACK_TYPES_H_
#define __COMSTACK_TYPES_H_

/* ElSokara Team Autosar Vendor ID */
#define COM_STACK_VENDOR_ID  (0x007D)

/* Module Version 1.0.0 */
#define COM_STACK_TYPES_SW_MAJOR_VERSION           (1U)
#define COM_STACK_TYPES_SW_MINOR_VERSION           (0U)
#define COM_STACK_TYPES_SW_PATCH_VERSION           (0U)

/* AUTOSAR Version 4.3.1 */
#define COM_STACK_TYPES_AR_RELEASE_MAJOR_VERSION   (4U)
#define COM_STACK_TYPES_AR_RELEASE_MINOR_VERSION   (3U)
#define COM_STACK_TYPES_AR_RELEASE_PATCH_VERSION   (1U)


#include "../Vertical_Layer/Std_Types.h"
/* AUTOSAR checking between Std Types and CAN_ComStack_Types Modules */
#if ((STD_TYPES_AR_RELEASE_MAJOR_VERSION != COM_STACK_TYPES_AR_RELEASE_MAJOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_MINOR_VERSION != COM_STACK_TYPES_AR_RELEASE_MINOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_PATCH_VERSION != COM_STACK_TYPES_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Std_Types.h does not match the expected version"
#endif


/*This type shall be used within the entire AUTOSAR Com Stack of an ECU except for bus drivers.*/
typedef uint8 PduLengthType; 		

/*Variables of this type shall be used to store the basic information about a PDU of any type, 
namely a pointer variable pointing to its SDU (payload), a pointer to Meta Data of the PDU, 
and the corresponding length of the SDU in bytes.*/
typedef struct 
{
	uint8*         SduDataPtr; /*Pointer to the SDU (i.e. payload data) of the PDU. 
								The type of this pointer depends on the memory model being used 
								at compile time.*/
	uint8*         MetaDataPtr; /*Pointer to the meta data (e.g. CAN ID, socket ID, diagnostic addresses) 
								of the PDU, consisting of a sequence of meta data items. 
								The length and type of the meta data items is statically configured for 
								each PDU. Meta data items with more than 8 bits use platform byte order.*/
	PduLengthType  SduLength;   /*Length of the SDU in bytes.*/

}PduInfoType;

/*IcomConfigIdType defines the configuration ID. 
An ID of 0 is the default configuration. An ID greater than 0 shall identify a configuration 
for Pretended Networking. There is more than 1 configuration possible.*/
typedef uint8 IcomConfigIdType;

/*IcomSwitch_ErrorType defines the errors which can occur when activating 
or deactivating Pretended Networking.*/
typedef uint8 IcomSwitch_ErrorType;
#define ICOM_SWITCH_E_OK     (IcomSwitch_ErrorType)0x00U
#define ICOM_SWITCH_E_FAILED (IcomSwitch_ErrorType)0x01U



#endif
