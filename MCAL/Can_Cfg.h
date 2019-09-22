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

#define CAN_TIMEOUT_DURATION 


/* Specifies the CAN controller base address. */
#define CAN_CONTROLLER_BASE_ADDRESS 

#define CAN_CONTROLLER_1_ID 0U 
#define CAN_CONTROLLER_2_ID 1U

/* Enables / disables API Can_MainFunction_Write() for handling PDU transmission
events in polling mode. */ 
typedef uint8 CanProcessingType;
#define CAN_TX_PROCESSING_0 MIXED_PROCESSING
#define CAN_TX_PROCESSING_1 MIXED_PROCESSING

#define INTERRUPT_PROCESSING 0U   /* Interrupt Mode of operation*/
#define MIXED_PROCESSING     1U   /* Mixed Mode of operation  */
#define POLLING_PROCESSING  2U   /* Polling Mode of operation*/

/* This parameter describes the period for cyclic call to
Can_MainFunction_Read or Can_MainFunction_Write depending on the
referring item. Unit is seconds. Different poll-cycles will be configurable if
more than one CanMainFunctionPeriod is configured. In this case multiple
Can_MainFunction_Read() or Can_MainFunction_Write() will be provided
by the CAN Driver module.*/
#define CAN_MAIN_FUNCTION_PERIOD 

/* Specifies the value which is used to pad unspecified data in CAN FD
frames > 8 bytes for transmission. This is necessary due to the discrete
possible values of the DLC if > 8 bytes.
If the length of a PDU which was requested to be sent does not match the
allowed DLC values, the remaining bytes up to the next possible value
shall be padded with this value */
#define CAN_FD_PADDING_VALUE 0U

/*Specifies the type (Full-CAN or Basic-CAN) of a hardware object*/
#define CAN_HANDLE_TYPE BASIC_CAN

#define BASIC_CAN  0U /* For several L-PDUs are hadled by the hardware object */
#define FULL_CAN 1U /* For only one L-PDU (identifier) is handled by the hardware object */


/*Number of hardware objects used to implement one HOH. In case of a
HRH this parameter defines the number of elements in the hardware FIFO
or the number of shadow buffers, in case of a HTH it defines the number of
hardware objects used for multiplexed transmission or for a hardware FIFO
used by a FullCAN HTH.*/
#define CAN_HW_OBJ_COUNT 

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

#define NUM_OF_HOH 2U

#define MAX_HW_OBJ_COUNT_PER_HOH 1U
#define NUM_OF_MAIN_RW_PERSIODS 2U

#define CAN_CONFIG 	{                                       /* CanType */\
						{                                  /* CanGeneral*/\
                            {\
                                {0.001,0.005}                   /* CanGeneral\CanMainFunctionRWPeriods  */\
                            }\
						},\
						{                                /*CanConfigSet*/\
						    {\
							    {                            /* CanController[NUM_OF_CAN_CONTROLLERS]*/\
								    0,                       /* CanControllerId */\
								    STD_ON,                  /* CanControllerActivation */\
								    0x40041000,             /* CanControllerBaseAddress */\
								    CAN_TX_PROCESSING_0      /* CanTxProcessing*/\
							    },\
							    {\
							        1,                       /* CanControllerId */\
							        STD_ON,                  /* CanControllerActivation */\
							        0x40041000,             /* CanControllerBaseAddress */\
							        CAN_TX_PROCESSING_1      /* CanTxProcessing*/\
							    }\
						    },\
							{                                                                            /* CanHardwareObject[ NUM_OF_HOH ]*/\
						        {\
								    &TivaCan.CanConfigSet.CanController[0],  								/* CanControllerRef*/\
								    TRUE,                                         								/* CanHardwareObjectUsesPolling*/\
								    1,                                                                         /*  CanHwObjectCount */\
								    0,\
								    TRANSMIT_HOH,                                            					/* CanObjectType */\
								    &TivaCan.CanGeneral.CanMainFunctionRWPeriods.CanMainFunctionPeriod[0],  /* CanMainFunctionRWPeriodRef*/\
								    {\
						                {\
									        CAN_MSG_CONF,\
									        1,\
									        13\
						                }\
								    }\
						        },\
						        {                            													/* CanHardwareObject[ NUM_OF_HOH ]*/\
						            &TivaCan.CanConfigSet.CanController[0],  								/* CanControllerRef*/\
						            TRUE,                                         								/* CanHardwareObjectUsesPolling*/\
						            1,																			/* CanHwObjectCount */\
						            1,\
						            TRANSMIT_HOH,                                            					/* CanObjectType */\
						            &TivaCan.CanGeneral.CanMainFunctionRWPeriods.CanMainFunctionPeriod[1],  /* CanMainFunctionRWPeriodRef*/\
						            {\
									    {\
						                    CAN_MSG_CONF,\
						                    2,\
						                    23\
									    }\
						            }\
						        }\
							}\
						}\
					}	









#endif
