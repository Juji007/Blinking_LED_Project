#ifndef HW_TYPES_H
#define HW_TYPES_H
#include "types.h"

#define Read_reg32(addr) *((volatile uint32 *)(addr))
	
#define Write_reg32(addr , val) *((volatile uint32 *)(addr)) = val

#define Write_reg32_mask(addr , val , mask) *((volatile uint32 *)(addr))=((Read_reg32(addr) & ~mask) | (mask & val))
	
#define Set_reg32_Pin(addr , pin) *((volatile uint32 *)(addr)) |= (1<<pin)
	
#define Clear_reg32_Pin(addr , pin) *((volatile uint32 *)(addr)) &= ~(1<<pin)

#define Togel_reg32_Pin(addr , pin) *((volatile uint32 *)(addr)) ^= (1<<pin)

#define Read_reg32_Pin(addr , pin ) ((*((volatile uint32 *)(addr))&(1<<pin))>>pin)



#endif
