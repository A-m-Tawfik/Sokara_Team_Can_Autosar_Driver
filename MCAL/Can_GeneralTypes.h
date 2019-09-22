#ifndef __CAN_GENERAL_TYPES_H_
#define __CAN_GENERAL_TYPES_H_

/* ElSokara Team Autosar Vendor ID */
#define CAN_VENDOR_ID  (0x007D)

/* Module Version 1.0.0 */
#define CAN_GENERAL_TYPES_SW_MAJOR_VERSION           (1U)
#define CAN_GENERAL_TYPES_SW_MINOR_VERSION           (0U)
#define CAN_GENERAL_TYPES_SW_PATCH_VERSION           (0U)

/* AUTOSAR Version 4.3.1 */
#define CAN_GENERAL_TYPES_AR_RELEASE_MAJOR_VERSION   (4U)
#define CAN_GENERAL_TYPES_AR_RELEASE_MINOR_VERSION   (3U)
#define CAN_GENERAL_TYPES_AR_RELEASE_PATCH_VERSION   (1U)

#include "../Vertical_Layer/Std_Types.h"
/* AUTOSAR checking between Std Types and CAN_GeneralTypes Modules */
#if ((STD_TYPES_AR_RELEASE_MAJOR_VERSION != CAN_GENERAL_TYPES_AR_RELEASE_MAJOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_MINOR_VERSION != CAN_GENERAL_TYPES_AR_RELEASE_MINOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_PATCH_VERSION != CAN_GENERAL_TYPES_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Std_Types.h does not match the expected version"
#endif

typedef boolean MsgConfType;
#define CAN_MSG_NOT_CONF 0U
#define CAN_MSG_CONF 1U

/*Represents the Identifier of an L-PDU. The two most significant bits specify the frame type:
00 CAN message with Standard CAN ID
01 CAN FD frame with Standard CAN ID
10 CAN message with Extended CAN ID
11 CAN FD frame with Extended CAN ID*/

typedef uint32 Can_IdType;

typedef uint32 PduIdType;


typedef struct MsgObj
{
	MsgConfType* MsgConfPtr;
	uint8       MsgId;
	PduIdType   PduId;
}MsgObjType;




 typedef struct CanMainFunctionRWPeriods
 {
     float32 CanMainFunctionPeriod[ NUM_OF_MAIN_RW_PERSIODS ];
 }CanMainFunctionRWPeriodsType;


 typedef struct CanGeneral
 {
	
	CanMainFunctionRWPeriodsType	CanMainFunctionRWPeriods;

 }CanGeneralType;





/*This is the type of the external data structure containing 
the overall initialization data for the CAN driver and SFR settings affecting all controllers. 
Furthermore it contains pointers to controller configuration structures. 
The contents of the initialization data structure are CAN hardware specific.*/
typedef struct 
{	
	Can_IdType        		CanControllerId;
	boolean           		CanControllerActivation;
	volatile uint64*	    CanControllerBaseAddress;
	CanProcessingType   	CanTxProcessing;
	


}Can_ConfigType;

/*This type unites PduId (swPduHandle), SduLength (length), SduData (sdu),
 and CanId (id) for any CAN L-SDU.*/
typedef struct 
{
	PduIdType  swPduHandle;
	uint8      length;
	Can_IdType id;
	uint8*     sdu;

}Can_PduType;


/*Represents the hardware object handles of a CAN hardware unit. 
For CAN hardware units with more than 255 HW objects use extended range.*/

typedef uint16 Can_HwHandleType;

/*This type defines a data structure which clearly provides an Hardware Object
Handle including its corresponding CAN Controller and therefore CanDrv as well
as the specific CanId.*/
typedef struct 
{
	Can_IdType       CanId;
	Can_HwHandleType Hoh;
	uint8            ControllerId;
}Can_HwType;


typedef uint8 CanObjectTypeType;
#define TRANSMIT_HOH (CanObjectTypeType)0U
#define RECEIVE_HOH  (CanObjectTypeType)1U

typedef struct 
{
	Can_ConfigType*  			   CanControllerRef;                /* Reference to CAN Controller to which the HOH is associated to */ 
																	
	boolean          			   CanHardwareObjectUsesPolling;    /* Enables polling of this hardware object */
	
	uint16			 			   CanHwObjectCount;                /* Number of hardware objects used to implement one HOH. In case of a
																	HRH this parameter defines the number of elements in the hardware FIFO
																	or the number of shadow buffers, in case of a HTH it defines the number of
																	hardware objects used for multiplexed transmission or for a hardware FIFO
																	used by a FullCAN HTH */
	
	uint8							CanObjectId;                	/* Holds the handle ID of HRH or HTH. The value of this parameter is unique
																	in a given CAN Driver, and it should start with 0 and continue without any
																	gaps.
																	The HRH and HTH Ids share a common ID range.
																	Example: HRH0-0, HRH1-1, HTH0-2, HTH1-3 */
																	
	CanObjectTypeType				CanObjectType;                  /* Specifies if the HardwareObject is used as Transmit or as Receive object*/
	
	CanMainFunctionRWPeriodsType*   CanMainFunctionRWPeriodRef;     /* Reference to CanMainFunctionPeriod */

	MsgObjType						MsgObj[MAX_HW_OBJ_COUNT_PER_HOH]; /* Mssage Object array of struct pre HOH */ 
	

}CanHardwareObjectType;


typedef struct CanConfigSet
 {
     /*
      * This container contains the configuration parameters of the CAN controller(s).
      */
     Can_ConfigType CanController[NUM_OF_CAN_CONTROLLERS];
     /*
      * This container contains the configuration (parameters) of CAN Hardware Objects.
      */
     CanHardwareObjectType CanHardwareObject[ NUM_OF_HOH ];
     /*
      * This container contains the parameters for configuring pretended networking
      */

 }CanConfigSetType;


/* Can:
 * This container holds the configuration of a single CAN Driver.
 */
typedef struct Can
{

   CanGeneralType CanGeneral;

   CanConfigSetType CanConfigSet;

}CanType;


/*Overlaid return value of Std_ReturnType for CAN driver API Can_Write() */
#define CAN_BUSY (Std_ReturnType)0x02U 

/*Error states of a CAN controller*/
typedef uint8 Can_ErrorStateType;

#define CAN_ERRORSTATE_ACTIVE  (Can_ErrorStateType) 0U
#define CAN_ERRORSTATE_PASSIVE (Can_ErrorStateType) 1U
#define CAN_ERRORSTATE_BUSOFF  (Can_ErrorStateType) 2U

/*States that are used by the several ControllerMode functions*/
typedef uint8 Can_ControllerStateType;
#define CAN_CS_UNINIT  (Can_ControllerStateType) 0x00U
#define CAN_CS_STARTED (Can_ControllerStateType) 0x01U
#define CAN_CS_STOPPED (Can_ControllerStateType) 0x02U
#define CAN_CS_SLEEP   (Can_ControllerStateType) 0x03U



#endif
