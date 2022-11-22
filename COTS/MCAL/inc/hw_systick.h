#ifndef HW_SYSTICK_H
#define	HW_SYSTICK_H

#define CORTEXM4_PERI_BASE_ADDRESS             0xE000E000

#define STCTRL		 *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x010))
#define STRELOAD 	 *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x014))
#define STCURRENT  *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x018))
#define SYSHNDCTRL  *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD24))
#define SYSPRI3  *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD20))
#define INTCTRL  *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD04))




#endif //HW_SYSTICK_H