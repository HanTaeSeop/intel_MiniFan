#include "Fan_mannual.h"

//void Fan_init()
//{
	//
//}

void Fan_mannualRun()
{
	uint8_t fanModeState;
	fanModeState = Model_getFanMode();
	if(fanModeState != MANNUAL) return;
	
	uint8_t fanWindState;
	fanWindState = Model_getFanWind();
	switch(fanWindState)
	{
		case OFF :
		Motor_Off();
		break;
		
		case WEAK :
		Motor_change(8);
		_delay_ms(100);
		TCNT3 = 0;
		break;
		
		case NORMAL :
		Motor_change(4);
		_delay_ms(100);
		TCNT3 = 0;
		break;
		
		case STRONG :
		Motor_change(2);
		_delay_ms(100);
		TCNT3 = 0;
		break;
	}

}