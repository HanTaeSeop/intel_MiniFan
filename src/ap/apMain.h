
#ifndef APMAIN_H_
#define APMAIN_H_
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "../driver/Motor/Motor.h"
#include "../driver/FND/fnd.h"

#include "Listener/Listener.h"
#include "Presenter/Presenter.h"

#include "Service/Fan_mannual.h"
#include "Service/Fan_auto.h"
#include "Service/Fan_timer.h"
#include "Service/Fan_UART0.h"


#include "Model/Model_fanMode.h"
#include "Model/Model_fanWind.h"
#include "Model/Model_fanTime.h"
#include "Model/Model_fanTimerStart.h"
#include "Model/Model_Fan_Sound.h"

#include "../Peri/Timer/Timer.h"


void apMain_init();
void apMain_run();

#endif /* APMAIN_H_ */