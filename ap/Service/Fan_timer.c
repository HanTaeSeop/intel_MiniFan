#include "Fan_timer.h"

static uint16_t milisec;
static uint8_t sec,min,hour;
volatile bool timer_running = true;

void FanTimer_init()
{
	milisec = 0;
	sec = 0;
	min = 0;
	hour = 0;
}

// state에 따른 timer 초기 값 변경 함수
void FanTimer_Mode()
{
	uint8_t fanTime = Model_getFanTime();
	switch(fanTime)
	{
		case CON :
		milisec = 0;
		sec = 0;
		min = 0;
		hour = 0;
		break;
		case MIN3 :
		milisec = 0;
		sec = 10;
		min = 0;
		hour = 0;
		break;
		case MIN5 :
		milisec = 0;
		sec = 0;
		min = 5;
		hour = 0;
		break;
		case MIN7 :
		milisec = 0;
		sec = 0;
		min = 7;
		hour = 0;
		break;
	}
}

void FanTimer_decMilisec()
{

	//if (!timer_running) return;
	
	if (milisec > 0)
	{
		milisec--;
	}
	else
	{
		milisec = 999;
		if (sec > 0)
		{
			sec--;
		}
		else
		{
			sec = 59;
			if (min > 0)
			{
				min--;
			}
			else
			{
				min = 59;
				if (hour > 0)
				{
					hour--;
				}
				else
				{
					milisec = 0;
					sec = 0;
					min = 0;
					hour = 0;
					//timer_running = false;
					Model_setFanTimer_Start(STOP);
					Model_setFanMode(MANNUAL);
					Model_setFanWind(OFF);
					Model_setFanTimer_Start(CON);
					Sound_End();
				}
			}
		}
	}
}

void FanTimer_disp()
{
	Preseter_dispTimerData(hour,min,sec,milisec);
}



//start버튼