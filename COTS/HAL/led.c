#include "led.h"
#include "hw_gpio.h"
#include "intCtrl.h"


void Blinking_LED(float OnTime , float OffTime){

Systick_Disable();
if (Read_reg32_Pin(Base+GPIO_DATA_OFFSET,lED_Pin) == 0 ){
	if(OnTime <= 0){
	STCURRENT = 0x0;
	STRELOAD = (OffTime * Systick_Clock) ;
	Systick_Enable();
	}else{
		
	Togel_reg32_Pin(Base+GPIO_DATA_OFFSET,lED_Pin);
	STCURRENT = 0x0;
	STRELOAD = (OnTime * Systick_Clock) ;
	Systick_Enable();
}
	}

else if(Read_reg32_Pin(Base+GPIO_DATA_OFFSET,lED_Pin) == 1 ){
	if(OffTime <= 0){
	STCURRENT = 0x0;
	STRELOAD = (OnTime * Systick_Clock) ;
	Systick_Enable();
	}else{
	
	Togel_reg32_Pin(Base+GPIO_DATA_OFFSET,lED_Pin);
	STCURRENT = 0x0;
	STRELOAD = (OffTime * Systick_Clock) ;
	Systick_Enable();
}

}
}

