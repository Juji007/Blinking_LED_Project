#ifndef LED_H
#define LED_H

#define Base 		GPIO_PORTF_BASE   // Choose GPIO PORT TO Attatch LED_Pin To
#define lED_Pin 			1           // GPIO PORT PIN Number Attatched to LED


#include "bitm.h"
#include "gpio.h"
#include "systick.h"

void Blinking_LED(float OnTime , float OffTime);



#endif // LED_H