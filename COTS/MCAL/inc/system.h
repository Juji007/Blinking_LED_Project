#ifndef SYSTEM_H
#define	SYSTEM_H
#include "hw_system.h"
#include "bitm.h"


typedef enum gpioPort{
GPIOA = 1 , GPIOB , GPIOC , GPIOD , GPIOE , GPIOF
}gpioPort_t;


void PORT_UNLOCK_CLOCK (gpioPort_t port);
#endif //SYSTEM_H
