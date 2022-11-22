#include "hw_systick.h"
#include "bitm.h"


#define Systick_Clock 16000000

void Systick_Disable();
void initSystick(float load);
void Systick_Enable();
