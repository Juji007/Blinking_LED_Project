#include "stdio.h"
#include "system.h"
#include "gpio.h"
#include "systick.h"
#include "led.h"

float OnTime = 1	; // LED On Time in Sec
float OffTime = 1 ;// LED Off Time in Sec


int main(void){
	
GPIOConfig_t MyPort;
 	MyPort.base = GPIO_PORTF_BASE;
	MyPort.Pin = 1;
	MyPort.dir = OUTPUT;
	MyPort.PadConfig.currentValue = CURRENT_2MA;
	MyPort.PadConfig.pulltype = PULL_DOWN;
	
	initPort(&MyPort);
	
	initSystick(OffTime);	
	
	while (1){
	// Waiting for interrupt
		
	}
	
  return 0;
}

void SysTick_Handler(){
		Blinking_LED(OnTime,OffTime);
}
