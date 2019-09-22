#ifndef __CAN_CFG_H_
#define __CAN_CFG_H_

/* Module Version 1.0.0 */
#define CAN_CFG_SW_MAJOR_VERSION           (1U)
#define CAN_CFG_SW_MINOR_VERSION           (0U)
#define CAN_CFG_SW_PATCH_VERSION           (0U)

/* AUTOSAR Version 4.3.1 */
#define CAN_CFG_AR_RELEASE_MAJOR_VERSION   (4U)
#define CAN_CFG_AR_RELEASE_MINOR_VERSION   (3U)
#define CAN_CFG_AR_RELEASE_PATCH_VERSION   (1U)

/*Non-Autosar file*/
#include "tm4c123gh6pm.h"

#include "../Vertical_Layer/Std_Types.h"
/* AUTOSAR checking between Std Types and Can_Cfg Modules */
#if ((STD_TYPES_AR_RELEASE_MAJOR_VERSION != CAN_CFG_AR_RELEASE_MAJOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_MINOR_VERSION != CAN_CFG_AR_RELEASE_MINOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_PATCH_VERSION != CAN_CFG_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Std_Types.h does not match the expected version"
#endif

/* Switches the development error detection and notification on or off */
#define CAN_DEV_ERROR_DETECT					STD_OFF

/* Specifies the InstanceId of this module instance. If only one instance is
present it shall have the Id 0.*/
#define CAN_INDEX  								(uint8)(0U)

/* Specifies if multiplexed transmission shall be supported.ON or OFF */
#define CAN_MULTIPLEXED_TRANSMISSION 			STD_OFF

/* Selects support of Pretended Network features in Can driver. */
#define CAN_PUBLIC_ICOM_SUPPORT 				STD_OFF

/* Enables / disables API Can_MainFunction_Write() for handling PDU transmission
events in polling mode. */ 
typedef uint8 CanProcessingType;
#define CAN_TX_PROCESSING_0 MIXED_PROCESSING
#define CAN_TX_PROCESSING_1 MIXED_PROCESSING

#define INTERRUPT_PROCESSING 0U   /* Interrupt Mode of operation*/
#define MIXED_PROCESSING     1U   /* Mixed Mode of operation  */
#define POLLING_PROCESSING  2U   /* Polling Mode of operation*/



/*Specifies the type (Full-CAN or Basic-CAN) of a hardware object*/
#define CAN_HANDLE_TYPE BASIC_CAN

#define BASIC_CAN  0U /* For several L-PDUs are hadled by the hardware object */
#define FULL_CAN 1U /* For only one L-PDU (identifier) is handled by the hardware object */

/* Specifies whether the IdValue is of type
- standard identifier
- extended identifier
- mixed mode
ImplementationType: Can_IdType*/
#define CAN_ID_TYPE STANDARD_CAN

#define EXTENDED_CAN  0U /* All the CANIDs are of type extended only(29 bit).*/
#define MIXED_CAN     1U /* The type of CANIDs can be both Standard or Extended.*/
#define STANDARD_CAN  2U /* All the CANIDs are of type standard only(11bit).*/

/*Holds the handle ID of HRH or HTH. The value of this parameter is unique
in a given CAN Driver, and it should start with 0 and continue without any
gaps.
The HRH and HTH Ids share a common ID range.
Example: HRH0-0, HRH1-1, HTH0-2, HTH1-3*/
#define CAN_OBJ_ID 0U




/* This parameter defines if or if not Can supports the trigger-transmit API for this handle*/
#define CAN_TRIGGER_TRANSMIT_ENABLE STD_OFF


#define NUM_OF_CAN_CONTROLLERS 2U
#define CONTROLLER_0_ID 0U
#define CONTROLLER_1_ID 1U
#define CONTROLLER_0_BASE_ADD (volatile uint64*)0x40040000
#define CONTROLLER_1_BASE_ADD (volatile uint64*)0x40041000

#define NUM_OF_HOH 2U
#define HOH_0_ID 0U
#define HOH_1_ID 1U
#define HOH_0_OBJ_CNT 1U
#define HOH_1_OBJ_CNT 1U

#define MAX_HW_OBJ_COUNT_PER_HOH 1U

#define MSG_OBJ_0_ID 1U
#define MSG_OBJ_1_ID 2U

#define PDU_0_ID 13U
#define PDU_1_ID 23U

#define NUM_OF_MAIN_RW_PERSIODS 2U
#define PERIOD_0 (float32) 0.001
#define PERIOD_1 (float32) 0.005

#define CAN_CONFIG 	{                                       /* CanType */\
						{                                  /* CanGeneral*/\
                            {\
                                {0.001,0.005}                   /* CanGeneral\CanMainFunctionRWPeriods  */\
                            }\
						},\
						{                                /*CanConfigSet*/\
						    {\
							    {                            /* CanController[NUM_OF_CAN_CONTROLLERS]*/\
							        CONTROLLER_0_ID,                       /* CanControllerId */\
								    STD_ON,                  /* CanControllerActivation */\
								    CONTROLLER_0_BASE_ADD,             /* CanControllerBaseAddress */\
								    CAN_TX_PROCESSING_0      /* CanTxProcessing*/\
							    },\
							    {\
							        CONTROLLER_1_ID,                       /* CanControllerId */\
							        STD_ON,                  /* CanControllerActivation */\
							        CONTROLLER_1_BASE_ADD,             /* CanControllerBaseAddress */\
							        CAN_TX_PROCESSING_1      /* CanTxProcessing*/\
							    }\
						    },\
							{                                                                            /* CanHardwareObject[ NUM_OF_HOH ]*/\
						        {\
								    (Can_ConfigType*)&TivaCan.CanConfigSet.CanController[CONTROLLER_0_ID],  								/* CanControllerRef*/\
								    TRUE,                                         								/* CanHardwareObjectUsesPolling*/\
								    HOH_0_OBJ_CNT,                                                                         /*  CanHwObjectCount */\
								    HOH_0_ID,\
								    TRANSMIT_HOH,                                            					/* CanObjectType */\
								    (CanMainFunctionRWPeriodsType*)&TivaCan.CanGeneral.CanMainFunctionRWPeriods,  /* CanMainFunctionRWPeriodRef*/\
								    {\
						                {\
									        &MsgConf[0],\
									        MSG_OBJ_0_ID,\
									        PDU_0_ID\
						                }\
								    }\
						        },\
						        {                            													/* CanHardwareObject[ NUM_OF_HOH ]*/\
						            (Can_ConfigType*)&TivaCan.CanConfigSet.CanController[CONTROLLER_0_ID],  								/* CanControllerRef*/\
						            TRUE,                                         								/* CanHardwareObjectUsesPolling*/\
						            HOH_1_OBJ_CNT,																			/* CanHwObjectCount */\
						            HOH_1_ID,\
						            TRANSMIT_HOH,                                            					/* CanObjectType */\
						            (CanMainFunctionRWPeriodsType*)&TivaCan.CanGeneral.CanMainFunctionRWPeriods,  /* CanMainFunctionRWPeriodRef*/\
						            {\
									    {\
						                    &MsgConf[1],\
						                    MSG_OBJ_1_ID,\
						                    PDU_0_ID\
									    }\
						            }\
						        }\
							}\
						}\
					}	









#endif
