#include "systick.h"
#include "bitm.h"
#include "hw_gpio.h"
#include "gpio.h"



void initSystick(float load){

//SYSHNDCTRL |=(1U<<11); // activate systick interrupt
	
//STCTRL &= ~(1<<2);    //  clock sorce as (PIOSC / 4)
STCTRL |=  (1<<2);  // clock sorce as System Clock
	
STCTRL |=  (1<<1);  // Enable interrupt
//STCTRL &= ~(1<<1);  // Disable interrupt
	
STCTRL |=  (1<<0); // Couter Enable

STCURRENT = 0;		// reset current value
STRELOAD = load * Systick_Clock;	// load value 
	

//INTCTRL |=(1U<<26); // Set pending flag

}

void Systick_Enable(){
STCTRL |= (1<<0);
}
void Systick_Disable(){
STCTRL &= ~(1<<0);

}