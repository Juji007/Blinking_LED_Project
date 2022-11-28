#ifndef HW_INTCTRL_H
#define HW_INTCTRL_H
#include "types.h"

#define CORTEXM4_PERI_BASE_ADDRESS             0xE000E000

#define INTCTRL  *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD04))
#define SYSPRI1  *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD18))
#define SYSPRI3  *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD20))
#define SYSHNDCTRL  *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD24))
#endif //HW_INTCTRL_H

