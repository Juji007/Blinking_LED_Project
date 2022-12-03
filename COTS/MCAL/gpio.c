#include "gpio.h"
#include "system.h"

gpioError_t SetPortDir ( uint32 addr ,uint8 val){
gpioError_t state = WORKING;
	if(addr == GPIO_PORTA_BASE ||addr == GPIO_PORTB_BASE ||addr == GPIO_PORTC_BASE ||addr == GPIO_PORTD_BASE ||addr == GPIO_PORTE_BASE ||addr == GPIO_PORTF_BASE ){
		
		Write_reg32((addr+GPIO_DIRECTION_OFFSET),val);
		
}else state = WRONG_PORT;
	
return state;

}

gpioError_t WritePort ( uint32 addr ,uint8 val){
gpioError_t state = WORKING;
	if(addr == GPIO_PORTA_BASE ||addr == GPIO_PORTB_BASE ||addr == GPIO_PORTC_BASE ||addr == GPIO_PORTD_BASE ||addr == GPIO_PORTE_BASE ||addr == GPIO_PORTF_BASE ){
		
		Write_reg32((addr+GPIO_DATA_OFFSET),val);
		
}else state = WRONG_PORT;
	
return state;

}
gpioError_t ReadPort ( uint32 addr ,uint8 *val){
gpioError_t state = WORKING;
	if(addr == GPIO_PORTA_BASE ||addr == GPIO_PORTB_BASE ||addr == GPIO_PORTC_BASE ||addr == GPIO_PORTD_BASE ||addr == GPIO_PORTE_BASE ||addr == GPIO_PORTF_BASE ){
		
		*val = (uint8)Read_reg32((addr+GPIO_DATA_OFFSET));
		
}else state = WRONG_PORT;
	
return state;

}
uint32 GPIO_READ_PIN(uint32 addr , uint8 pin){
	
return ((*((volatile uint32 *)(addr+GPIO_DATA_OFFSET))&(1<<pin))>>pin);

}
void GPIO_CLEAR_PIN(uint32 addr , uint8 pin){
	
*((volatile uint32 *)(addr+GPIO_DATA_OFFSET)) &= ~(1<<pin) ;

}
void initPort(GPIOConfig_t *config){
	//Unlock and Commit
Write_reg32((config->base+GPIO_LOCK_OFFSET),0x4C4F434B);
Set_reg32_Pin((config->base+GPIO_COMMIT_OFFSET),config->Pin);
	
	//Port Clock Enable
if(config->base == GPIO_PORTA_BASE){
	
PORT_UNLOCK_CLOCK(GPIOA);
}else if(config->base == GPIO_PORTB_BASE){
PORT_UNLOCK_CLOCK(GPIOB);
}else if(config->base == GPIO_PORTC_BASE){
PORT_UNLOCK_CLOCK(GPIOC);
}else if(config->base == GPIO_PORTD_BASE){
PORT_UNLOCK_CLOCK(GPIOD);
}else if(config->base == GPIO_PORTE_BASE){
PORT_UNLOCK_CLOCK(GPIOE);
}else if(config->base == GPIO_PORTF_BASE){
PORT_UNLOCK_CLOCK(GPIOF);
}
if(config->dir == OUTPUT){
Set_reg32_Pin((config->base+GPIO_DIRECTION_OFFSET),config->Pin);
}else if (config->dir == INPUT){
Clear_reg32_Pin((config->base+GPIO_DIRECTION_OFFSET),config->Pin);
}
if(config->PadConfig.altFun == TRUE){
Set_reg32_Pin((config->base)+GPIO_ALTERNATE_FUNC_SEL_OFFSET,config->Pin);
}
else if(config->PadConfig.altFun == FALSE){
Clear_reg32_Pin((config->base)+GPIO_ALTERNATE_FUNC_SEL_OFFSET,config->Pin);
}else {
/* */
}
if(config->PadConfig.currentValue == CURRENT_2MA){
Set_reg32_Pin((config->base)+GPIO_2_MA_DRIVE_SEL_OFFSET,config->Pin);
}else if(config->PadConfig.currentValue == CURRENT_4MA){
Set_reg32_Pin((config->base)+GPIO_4_MA_DRIVE_SEL_OFFSET,config->Pin);
}else if(config->PadConfig.currentValue == CURRENT_8MA){
Set_reg32_Pin((config->base)+GPIO_8_MA_DRIVE_SEL_OFFSET,config->Pin);
}
if(config->PadConfig.pulltype == PULL_UP){
Set_reg32_Pin((config->base)+GPIO_PULL_UP_SEL_OFFSET,config->Pin);
}else if(config->PadConfig.pulltype == PULL_DOWN){
Set_reg32_Pin((config->base)+GPIO_PULL_DOWN_SEL_OFFSET,config->Pin);
}else if(config->PadConfig.pulltype == OPEN_DRAIN){
Set_reg32_Pin((config->base)+GPIO_OPEN_DRAIN_SEL_OFFSET,config->Pin);
}
Set_reg32_Pin((config->base)+GPIO_DIGITAL_EN_OFFSET,config->Pin); // Digital Enable

}

