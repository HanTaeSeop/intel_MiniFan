
#ifndef MODEL_FANTIME_H_
#define MODEL_FANTIME_H_

#define F_CPU 16000000UL
#include <avr/io.h>

enum{CON,MIN3,MIN5,MIN7};

uint8_t Model_getFanTime();
void Model_setFanTime(uint8_t data);

#endif /* MODEL_FANTIME_H_ */