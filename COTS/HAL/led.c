#include "led.h"
#include "hw_gpio.h"



void Blinking_LED(float OnTime , float OffTime){

Systick_Disable();
if (Read_reg32_Pin(Base+GPIO_DATA_OFFSET,lED_Pin) == 0 ){
	
	Togel_reg32_Pin(Base+GPIO_DATA_OFFSET,lED_Pin);
	//STCURRENT = 0;
	Systick_Enable();
	STRELOAD = (OffTime * Systick_Clock) ;
}

else if(Read_reg32_Pin(Base+GPIO_DATA_OFFSET,lED_Pin) == 1 ){
	
	Togel_reg32_Pin(Base+GPIO_DATA_OFFSET,lED_Pin);
	//STCURRENT = 0;
	Systick_Enable();
	STRELOAD = (OnTime * Systick_Clock) ;
}

INTCTRL |=(1U<<25); // Clear pending flag
}



