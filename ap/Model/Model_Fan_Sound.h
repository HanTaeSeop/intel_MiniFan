

#ifndef MODEL_FAN_SOUND_H_
#define MODEL_FAN_SOUND_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#include "../../driver/Buzzer/Buzzer.h"

void Fansound_init();
void Sound_start();
void Sound_Auto();
void Sound_Mannual();
void Sound_Timer();
void Sound_Wind();
void Sound_Start();
void Sound_End();
#endif /* FAN_SOUND_H_ */