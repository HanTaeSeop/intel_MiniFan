
#ifndef FAN_MANNUAL_H_
#define FAN_MANNUAL_H_
#define F_CPU 16000000UL
#include <avr/io.h>

#include "../Model/Model_fanMode.h"
#include "../Model/Model_fanWind.h"
#include "../../driver/Motor/Motor.h"

void Fan_mannualRun();

#endif /* FAN_MANNUAL_H_ */