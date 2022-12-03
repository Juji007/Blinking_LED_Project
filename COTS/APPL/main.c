#include "stdio.h"
#include "system.h"
#include "gpio.h"
#include "systick.h"
#include "led.h"
#include "intCtrl.h"

float OnTime = 2	; // LED On Time in Sec
float OffTime = 2 ;// LED Off Time in Sec


void handle_systick_isr(){
	
Blinking_LED(OnTime,OffTime);
}

int main(void){
	
GPIOConfig_t myLED;
 	myLED.base = GPIO_PORTF_BASE;
	myLED.Pin = 1;
	myLED.dir = OUTPUT;
	myLED.PadConfig.currentValue = CURRENT_2MA;
	myLED.PadConfig.pulltype = PULL_DOWN;
	
	GPIOConfig_t myButton1;          // increase ON time and dcrease OFF time up to 4 Sec
	myButton1.base = GPIO_PORTD_BASE;
	myButton1.Pin = 1;
	myButton1.dir = INPUT;
	myButton1.PadConfig.pulltype = PULL_DOWN;
	
	GPIOConfig_t myButton2;    // increase OFF time and dcrease ON time up to 4 Sec
	myButton2.base = GPIO_PORTD_BASE;
	myButton2.Pin = 2;
	myButton2.dir = INPUT;
	myButton2.PadConfig.pulltype = PULL_DOWN;
	
	initPort(&myLED);
	initPort(&myButton1);
	initPort(&myButton2);
	
	Enable_IR(busFalult,1); // Enable bus fault
	Enable_IR(usageFault,0);  // Enable usage fault
	
	register_systick_CBFun(&handle_systick_isr);
	
	initSystick(OffTime);	
	
	while (1){
	
	if((GPIO_READ_PIN(myButton1.base,myButton1.Pin)== 1) && (OnTime < 4)){
	++OnTime;
	--OffTime;
  GPIO_CLEAR_PIN(myButton1.base,myButton1.Pin);
		
	}
		if((GPIO_READ_PIN(myButton2.base,myButton2.Pin)==1) && (OffTime < 4)){
	--OnTime;
	++OffTime;
	GPIO_CLEAR_PIN(myButton2.base,myButton2.Pin);
		
	}
	
	}
  return 0;
}


