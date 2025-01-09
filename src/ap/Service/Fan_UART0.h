

#ifndef FAN_UART0_H_
#define FAN_UART0_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <string.h>
#include <stdio.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "../../Peri/UART0/UART0.h"
#include "../Model/Model_fanMode.h"
#include "../Model/Model_fanWind.h"
#include "../Model/Model_fanTime.h"
#include "../Model/Model_fanTimerStart.h"
#include "../Model/Model_Fan_Sound.h"

void FanUart0_run();

#endif /* FAN_UART0_H_ */