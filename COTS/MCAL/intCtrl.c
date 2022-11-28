#include "intCtrl.h"

void Enable_IR(IRName_t IRName,priorityVal val){

	if(IRName == usageFault){
	
		SYSHNDCTRL |=(1U<<18); // Enable handler
		
		SYSPRI1 |=(val<<21);  // Set priority
	
	}else if (IRName == busFalult){
	
	SYSHNDCTRL |=(1U<<17); // Enable handler
		
	SYSPRI1 |=(val<<13);  // Set priority
	}else if (IRName == memoryManagemenFault){
	
	SYSHNDCTRL |=(1U<<16); // Enable handler
		
	SYSPRI1 |=(val<<5);  // Set priority
	}
}
void Disable_IR(IRName_t IRName){

	if(IRName == usageFault){
	
		SYSHNDCTRL &= ~(1U<<18); // Enable handler
		
	}else if (IRName == busFalult){
	
	SYSHNDCTRL &= ~(1U<<17); // Enable handler
		
	}else if (IRName == memoryManagemenFault){
	
	SYSHNDCTRL &= ~(1U<<16); // Enable handler
		
}

}