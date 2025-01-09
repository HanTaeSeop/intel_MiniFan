#include "Fan_UART0.h"




void FanUart0_run()
{
	if(UART0_getRxFlag())
	{
		UART0_clearRxFlag();
		uint8_t* rxString = UART0_readRxBuff();
		uint8_t state;
		uint8_t data;
		
		if(!strcmp((char*)rxString,"Fan_mannual\n"))
		{
			state = MANNUAL;
			Model_setFanMode(state);
			Model_setFanWind(OFF);
			Model_setFanTimer_Start(STOP);
			Model_setFanTime(CON);
			Sound_Mannual();
			if(state == MANNUAL)
			{
				printf("STATE : MANNUAL\n");
			}
		}
		if(!strcmp((char*)rxString,"Fan_Auto\n"))
		{
			state = AUTO;
			Model_setFanMode(AUTO);
			Sound_Auto();
			if(state == AUTO)
			{
				printf("STATE : AUTO\n");
			}
		}
		if(!strcmp((char*)rxString,"Wind_change\n"))
		{
			uint8_t a = Model_getFanMode();
			if (a != MANNUAL)
			{
				printf("Do it in MANNUAL mode\n");
				return;
			}
			static uint8_t i=0;
			switch(i)
			{
				case 0 :
				data = OFF;
				Sound_Wind();
				Model_setFanWind(data);
				i++;
				if(data == OFF)
				{
					printf("STATE : OFF\n");
				}
				break;
				case 1 :
				data = WEAK;
				Sound_Wind();
				Model_setFanWind(data);
				i++;
				if(data == WEAK)
				{
					printf("STATE : WEAK\n");
				}
				break;
				case 2 :
				data = NORMAL;
				Sound_Wind();
				Model_setFanWind(data);
				i++;
				if(data == NORMAL)
				{
					printf("STATE : NORMAL\n");
				}
				break;
				case 3 :
				data = STRONG;
				Sound_Wind();
				Model_setFanWind(data);
				i=0;
				if(data == STRONG)
				{
					printf("STATE : STRONG\n");
				}
				break;
			}
		}
	}
}