#ifndef __CANIF_CBK_H__
#define __CANIF_CBK_H__

/* Module Version 1.0.0 */
#define CAN_IF_TYPES_SW_MAJOR_VERSION           (1U)
#define CAN_IF_TYPES_SW_MINOR_VERSION           (0U)
#define CAN_IF_TYPES_SW_PATCH_VERSION           (0U)

/* AUTOSAR Version 4.3.1 */
#define CAN_IF_TYPES_AR_RELEASE_MAJOR_VERSION   (4U)
#define CAN_IF_TYPES_AR_RELEASE_MINOR_VERSION   (3U)
#define CAN_IF_TYPES_AR_RELEASE_PATCH_VERSION   (1U)


#include "../Vertical_Layer/Std_Types.h"
/* AUTOSAR checking between Std Types and CAN Modules */
#if ((STD_TYPES_AR_RELEASE_MAJOR_VERSION != CAN_IF_TYPES_AR_RELEASE_MAJOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_MINOR_VERSION != CAN_IF_TYPES_AR_RELEASE_MINOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_PATCH_VERSION != CAN_IF_TYPES_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Std_Types.h does not match the expected version"
#endif


typedef uint32 PduIdType;

void CanIf_TxConfirmation(PduIdType CanTxPduId);

#endif //__CANIF_CBK_H__
