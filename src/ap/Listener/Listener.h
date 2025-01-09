
#ifndef LISTENER_H_
#define LISTENER_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

//참조
#include "../../driver/Button/button.h"
#include "../Model/Model_fanMode.h"
#include "../Model/Model_fanWind.h"
#include "../Model/Model_fanTime.h"
#include "../Model/Model_fanTimerStart.h"
#include "../Model/Model_Fan_Sound.h"
#include "../Service/Fan_timer.h"


//초기화
void Listener_init();

//동작
void Listener_fanModeCheck();

void Listener_fanWindCheck();

void Listener_fanTimeCheck();

void Listener_fanTimer_Start();


#endif /* LISTENER_H_ */