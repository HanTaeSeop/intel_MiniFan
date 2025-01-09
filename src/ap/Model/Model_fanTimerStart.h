

#ifndef MODEL_FANTIMERSTART_H_
#define MODEL_FANTIMERSTART_H_

#define F_CPU 16000000UL
#include "avr/io.h"

enum{STOP,START};

uint8_t Model_getFanTimer_Start();
void Model_setFanTimer_Start(uint8_t data);

#endif /* MODEL_FANTIMERSTART_H_ */