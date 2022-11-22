#ifndef GPIO_H
#define GPIO_H
#include "types.h"
#include "hw_gpio.h"
#include "bitm.h"


typedef enum gpioError {
WORKING = 1 , WRONG_PORT 
}gpioError_t;

typedef enum PullType{
PULL_UP = 1 , PULL_DOWN , OPEN_DRAIN
}PullType_t;

typedef enum CurrentVal {
CURRENT_2MA = 1 , CURRENT_4MA , CURRENT_8MA
}CurrrentVal_t;

typedef enum PortDir {
OUTPUT = 1 , INPUT
}PortDir_t;

typedef enum AltFun {
TRUE = 1 , FALSE
}AltFun_t;

typedef struct gpadConfig{
PullType_t pulltype;
CurrrentVal_t currentValue;
AltFun_t altFun;

}gpadConfig_t;


typedef struct GPIOConfig{
 uint32 base;
 uint8 Pin;
 PortDir_t dir;
 gpadConfig_t PadConfig;
	
}GPIOConfig_t;


gpioError_t setPortDir ( uint32 addr ,uint8 val);
gpioError_t WritePort ( uint32 addr ,uint8 val);
gpioError_t ReadPort ( uint32 addr ,uint8 *val);

void initPort(GPIOConfig_t *config);
#endif //APP_GPIO_H

