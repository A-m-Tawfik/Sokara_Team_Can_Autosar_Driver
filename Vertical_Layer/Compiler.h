#ifndef _COMPILER_H_
#define _COMPILER_H_

#define NULL ((void*)0x00)

#define ISR(vector)   void vector (void) __attribute__ ((signal,__INTR_ATTRS)); \
					  void vector (void)
					  
#define WDT_RESET()	  __asm__ __volatile__("wdr")

#define DISABLE_GLOBAL_INTERRUPT()  __asm__ __volatile__ ("cli" ::: "memory")
#define ENABLE_GLOBAL_INTERRUPT()   __asm__ __volatile__ ("sei" ::: "memory")


#define FORCE_INLINE inline __attribute__((always_inline))


#endif 
