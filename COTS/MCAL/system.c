#include "system.h"


void PORT_UNLOCK_CLOCK (gpioPort_t port){
if (port == GPIOA){
	Set_reg32_Pin(RCGCGPIO , 0);
}else if (port == GPIOB){
	Set_reg32_Pin(RCGCGPIO , 1);
}else if (port == GPIOC){
	Set_reg32_Pin(RCGCGPIO , 2);
}else if (port == GPIOD){
	Set_reg32_Pin(RCGCGPIO , 3);
}else if (port == GPIOE){
	Set_reg32_Pin(RCGCGPIO , 4);
}else if (port == GPIOF){
	Set_reg32_Pin(RCGCGPIO , 5);
}else{
	//nothing
}

}
