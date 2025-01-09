
#ifndef FAN_TIMER_H_
#define FAN_TIMER_H_

#define F_CPU 16000000UL
#include "avr/io.h"
#include "util/delay.h"
#include <stdbool.h>

#include "../Model/Model_fanTime.h"
#include "../Model/Model_fanMode.h"
#include "../Model/Model_fanTimerStart.h"
#include "../Model/Model_fanWind.h"
#include "../Model/Model_Fan_Sound.h"

#include "../Presenter/Presenter.h"

void FanTimer_init();
void FanTimer_Mode();
void FanTimer_decMilisec();

void FanTimer_disp();

#endif /* FAN_TIMER_H_ */