#ifndef __CAN_H_
#define __CAN_H_

/* ElSokara Team Autosar Vendor ID */
#define CAN_VENDOR_ID  (0x007D)

/* CAN Module ID */
#define CAN_MODULE_ID (uint16)(0x80U)
#define CAN_INSTANCE_ID (uint16)(0x07U)



/* Module Version 1.0.0 */
#define CAN_SW_MAJOR_VERSION           (1U)
#define CAN_SW_MINOR_VERSION           (0U)
#define CAN_SW_PATCH_VERSION           (0U)

/* AUTOSAR Version 4.3.1 */
#define CAN_AR_RELEASE_MAJOR_VERSION   (4U)
#define CAN_AR_RELEASE_MINOR_VERSION   (3U)
#define CAN_AR_RELEASE_PATCH_VERSION   (1U)

#include "../Vertical_Layer/Std_Types.h"
/* AUTOSAR checking between Std Types and CAN Modules */
#if ((STD_TYPES_AR_RELEASE_MAJOR_VERSION != CAN_AR_RELEASE_MAJOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_MINOR_VERSION != CAN_AR_RELEASE_MINOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_PATCH_VERSION != CAN_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Std_Types.h does not match the expected version"
#endif

#include "Can_Cfg.h"
/* AUTOSAR checking between Can_Cfg and CAN Modules */
#if ((CAN_CFG_AR_RELEASE_MAJOR_VERSION != CAN_AR_RELEASE_MAJOR_VERSION)\
 ||  (CAN_CFG_AR_RELEASE_MINOR_VERSION != CAN_AR_RELEASE_MINOR_VERSION)\
 ||  (CAN_CFG_AR_RELEASE_PATCH_VERSION != CAN_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Can_Cfg.h does not match the expected version"
#endif

#include "Can_GeneralTypes.h"
/* AUTOSAR checking between CAN_GeneralTypes and CAN Modules */
#if ((CAN_GENERAL_TYPES_AR_RELEASE_MAJOR_VERSION != CAN_AR_RELEASE_MAJOR_VERSION)\
 ||  (CAN_GENERAL_TYPES_AR_RELEASE_MINOR_VERSION != CAN_AR_RELEASE_MINOR_VERSION)\
 ||  (CAN_GENERAL_TYPES_AR_RELEASE_PATCH_VERSION != CAN_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of CAN_GeneralTypes.h does not match the expected version"
#endif

#include "ComStack_Types.h"
/* AUTOSAR checking between ComStack_Types and CAN Modules */
#if ((COM_STACK_TYPES_AR_RELEASE_MAJOR_VERSION != CAN_AR_RELEASE_MAJOR_VERSION)\
 ||  (COM_STACK_TYPES_AR_RELEASE_MINOR_VERSION != CAN_AR_RELEASE_MINOR_VERSION)\
 ||  (COM_STACK_TYPES_AR_RELEASE_PATCH_VERSION != CAN_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of ComStack_Types.h does not match the expected version"
#endif

#include "CanIf_Cbk.h"
/* AUTOSAR checking between CanIf_Cbk and CAN Modules */
#if ((CAN_IF_TYPES_AR_RELEASE_MAJOR_VERSION != CAN_AR_RELEASE_MAJOR_VERSION)\
 ||  (CAN_IF_TYPES_AR_RELEASE_MINOR_VERSION != CAN_AR_RELEASE_MINOR_VERSION)\
 ||  (CAN_IF_TYPES_AR_RELEASE_PATCH_VERSION != CAN_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of CanIf_Cbk.h does not match the expected version"
#endif



/* APIs Service Ids */ 
#define Can_GetControllerMode_SID  (uint8)(0x12)
#define Can_MainFunction_Write_SID (uint8)(0x01)

/* Development Errors Ids */ 
#define CAN_E_PARAM_POINTER       (uint8)(0x01)
#define CAN_E_PARAM_HANDLE        (uint8)(0x02)
#define CAN_E_PARAM_DATA_LENGTH   (uint8)(0x03)
#define CAN_E_PARAM_CONTROLLER    (uint8)(0x04)
#define CAN_E_UNINIT              (uint8)(0x05)
#define CAN_E_TRANSITION          (uint8)(0x06)
#define CAN_E_PARAM_BAUDRATE      (uint8)(0x07)
#define CAN_E_ICOM_CONFIG_INVALID (uint8)(0x08)
#define CAN_E_INIT_FAILED         (uint8)(0x09)

/* RunTime Errors Ids */ 
#define CAN_E_DATALOST (uint8)(0x01)

/* Function Prototypes*/ 


#define CAN_MAX_HW_OBJ (uint8)32U

/*This function performs the polling of TX confirmation when
CAN_TX_PROCESSING is set to POLLING.*/
void Can_MainFunction_Write(void);

/*This service reports about the current status of the requested CAN controller*/
Std_ReturnType Can_GetControllerMode(uint8 Controller,Can_ControllerStateType* ControllerModePtr);




#endif
