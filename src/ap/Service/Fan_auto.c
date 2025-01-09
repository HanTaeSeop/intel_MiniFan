#include "Fan_auto.h"

uint32_t timeTick;
uint8_t fanWindState;

void Fan_autoInit()
{
	timeTick = 0;
	fanWindState = Model_getFanWind();
}

void Fan_autoRun()
{
	uint8_t fanModeState = Model_getFanMode();
	if(fanModeState != AUTO) return;
	
	
	static uint32_t prevTime = 0;
	switch(fanWindState)
	{
		case OFF :
		Motor_Off();
		if(timeTick - prevTime >= 30)
		{
			prevTime = timeTick;
			fanWindState = WEAK;
			Model_setFanWind(WEAK);
		}
		break;
		
		case WEAK :
		Motor_change(8);
		
		TCNT3 = 0;
		if(timeTick - prevTime >= 30)
		{
			prevTime = timeTick;
			fanWindState = NORMAL;
			Model_setFanWind(NORMAL);
		}
		
		break;
		case NORMAL :
		Motor_change(4);
		
		TCNT3 = 0;
		if(timeTick - prevTime >= 30)
		{
			prevTime = timeTick;
			fanWindState = STRONG;
			Model_setFanWind(STRONG);
		}
		
		break;
		case STRONG :
		Motor_change(2);
		
		TCNT3 = 0;
		if(timeTick - prevTime >= 30)
		{
			prevTime = timeTick;
			fanWindState = OFF;
			Model_setFanWind(OFF);
		}
		
		break;
	}
	
	_delay_ms(1);
	timeTick++;
}