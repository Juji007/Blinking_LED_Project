#ifndef SYSTICK_H
#define SYSTICK_H
#include "hw_systick.h"
#include "bitm.h"
#include "stdio.h"

#define Systick_Clock 16000000

typedef void(*cb_ptr)(void);  // pointer to a function type

void register_systick_CBFun(cb_ptr ptr);

void Systick_Disable();
void initSystick(float load);
void Systick_Enable();

#endif //SYSTICK_H
