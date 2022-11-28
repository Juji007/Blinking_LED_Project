#include "systick.h"


cb_ptr callBack_ptr = NULL ;


void register_systick_CBFun(cb_ptr ptr){

if(ptr != NULL){

	callBack_ptr = ptr;
}
}
void SysTick_Handler(){
	
	if(callBack_ptr != NULL){
	
	callBack_ptr();
	}
}



void initSystick(float load){
	
//STCTRL &= ~(1<<2);    //  clock sorce as (PIOSC / 4)
STCTRL |=  (1<<2);  // clock sorce as System Clock
	
STCTRL |=  (1<<1);  // Enable interrupt
	
STCTRL |=  (1<<0); // Couter Enable

STCURRENT = 0;		// reset current value
	
STRELOAD = load * Systick_Clock;	// load value 


}

void Systick_Enable(){
STCTRL |= (1<<0);
}
void Systick_Disable(){
STCTRL &= ~(1<<0);

}
