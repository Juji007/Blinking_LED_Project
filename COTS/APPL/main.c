#include "stdio.h"
#include "system.h"
#include "gpio.h"
#include "systick.h"
#include "led.h"
#include "intCtrl.h"

float OnTime = 4	; // LED On Time in Sec
float OffTime = 1 ;// LED Off Time in Sec


void handle_systick_isr(){
	
Blinking_LED(OnTime,OffTime);
}

int main(void){
	
GPIOConfig_t MyPort;
 	MyPort.base = GPIO_PORTF_BASE;
	MyPort.Pin = 1;
	MyPort.dir = OUTPUT;
	MyPort.PadConfig.currentValue = CURRENT_2MA;
	MyPort.PadConfig.pulltype = PULL_DOWN;
	
	initPort(&MyPort);
	
	Enable_IR(busFalult,1); // Enable bus fault
	Enable_IR(usageFault,0);  // Enable usage fault
	
	register_systick_CBFun(&handle_systick_isr);
	
	initSystick(OffTime);	
	
	while (1){
		
	// Waiting for interrupt
	}
  return 0;
}


