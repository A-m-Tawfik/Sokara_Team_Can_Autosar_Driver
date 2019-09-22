#ifndef _PLATFORM_TYPES_H_ 
#define _PLATFORM_TYPES_H_

typedef unsigned char boolean;
typedef signed char sint8;
typedef unsigned char uint8;
typedef signed short sint16;
typedef unsigned short uint16;
typedef signed long sint32;
typedef signed long long sint64;
typedef unsigned long uint32;
typedef unsigned long long uint64;

typedef signed char    sint8_least;
typedef unsigned char  uint8_least;
typedef signed short   sint16_least;
typedef unsigned short uint16_least;
typedef signed long    sint32_least;
typedef unsigned long  uint32_least;

typedef float float32;
typedef double float64;


#define CPU_TYPE_8  (uint8)8
#define CPU_TYPE_16 (uint8)16
#define CPU_TYPE_32 (uint8)32
#define CPU_TYPE_64 (uint8)64

#define MSB_FIRST (uint8)0
#define LSB_FIRST (uint8)1

#define HIGH_BYTE_FIRST (uint8)0
#define LOW_BYTE_FIRST  (uint8)1

#define FALSE (uint8)0
#define TRUE  (uint8)1


#define CPU_TYPE CPU_TYPE_8
#define CPU_BIT_ORDER LSB_FIRST
#define CPU_BYTE_ORDER LOW_BYTE_FIRST


#endif 