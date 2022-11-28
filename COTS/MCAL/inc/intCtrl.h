#ifndef INTCTRL_H
#define INTCTRL_H
#include "hw_intCtrl.h"

typedef enum {
 usageFault = 1 , busFalult , memoryManagemenFault
}IRName_t;

typedef unsigned char priorityVal;


void Enable_IR(IRName_t IRName,priorityVal val);
void Disable_IR(IRName_t IRName);

#endif  //INTCTRL_H