#ifndef __STD_TYPES_H
#define __STD_TYPES_H

#include "Platform_Types.h"
#include "Compiler.h"

/* Module Version 1.0.0 */
#define STD_TYPES_SW_MAJOR_VERSION           (1U)
#define STD_TYPES_SW_MINOR_VERSION           (0U)
#define STD_TYPES_SW_PATCH_VERSION           (0U)

/* AUTOSAR Version 4.3.1 */
#define STD_TYPES_AR_RELEASE_MAJOR_VERSION   (4U)
#define STD_TYPES_AR_RELEASE_MINOR_VERSION   (3U)
#define STD_TYPES_AR_RELEASE_PATCH_VERSION   (1U)

typedef uint8 Std_ReturnType;

typedef struct 
{
	uint16 vendorID;
	uint16 moduleID;
	uint8 major_version;
	uint8 minor_version;
	uint8 patch_version;
	
}Std_VersionInfoType;

#define E_OK     (uint8)0x00U
#define E_NOT_OK (uint8)0x01U

#define STD_LOW  (uint8)0x00U
#define STD_HIGH (uint8)0x01U

#define STD_IDLE   (uint8)0x00U
#define STD_ACTIVE (uint8)0x01U

#define STD_OFF 0x00U
#define STD_ON  0x01U

#endif
