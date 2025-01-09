

#ifndef MODEL_FANWIND_H_
#define MODEL_FANWIND_H_
#define F_CPU 16000000UL
#include <avr/io.h>

enum{OFF,WEAK,NORMAL,STRONG};

uint8_t Model_getFanWind();


void Model_setFanWind(uint8_t data);

#endif /* MODEL_FANWIND_H_ */