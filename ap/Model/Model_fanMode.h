

#ifndef MODEL_FANMODE_H_
#define MODEL_FANMODE_H_
#define F_CPU 16000000UL
#include <avr/io.h>

enum{MANNUAL,AUTO};

uint8_t Model_getFanMode();
void Model_setFanMode(uint8_t data);
#endif /* MODEL_FANMODE_H_ */