#include "Listener.h"

button_t btn_mode,btn_wind,btn_timer,btn_start;

void Listener_init()
{
	Button_init(&btn_mode,&DDRA,&PINA,0);
	Button_init(&btn_wind,&DDRA,&PINA,1);
	Button_init(&btn_timer,&DDRA,&PINA,2);
	Button_init(&btn_start,&DDRA,&PINA,3);
}

void Listener_fanModeCheck()
{
	uint8_t fanMode =Model_getFanMode();
	switch(fanMode)
	{
		case MANNUAL :
		Listener_fanWindCheck();
		if(Button_GetState(&btn_mode)==ACT_RELEASED)
		{	
			Sound_Auto();
			fanMode = AUTO;
			Model_setFanMode(fanMode);
		}
		break;
		
		case AUTO :
		if(Button_GetState(&btn_mode)==ACT_RELEASED)
		{	
			Sound_Mannual();
			fanMode = MANNUAL;
			Model_setFanMode(fanMode);
		}
		break;
	}	
}

void Listener_fanWindCheck()
{
	uint8_t fanModeCheck = Model_getFanMode();
	if(fanModeCheck != MANNUAL) return;
	uint8_t fanWind = Model_getFanWind();
	switch(fanWind)
	{
		case OFF :
		
		if(Button_GetState(&btn_wind)==ACT_RELEASED)
		{
			Sound_Wind();
			fanWind = WEAK;
			Model_setFanWind(fanWind);
		}
		break;
		
		case WEAK :
		if(Button_GetState(&btn_wind)==ACT_RELEASED)
		{
			Sound_Wind();
			fanWind = NORMAL;
			Model_setFanWind(fanWind);
		}
		break;
		
		case NORMAL :
		if(Button_GetState(&btn_wind)==ACT_RELEASED)
		{
			Sound_Wind();
			fanWind = STRONG;
			Model_setFanWind(fanWind);
		}
		break;
		
		case STRONG :
		if(Button_GetState(&btn_wind)==ACT_RELEASED)
		{
			Sound_Wind();
			fanWind = OFF;
			Model_setFanWind(fanWind);
		}
		break; 
	}
}

void Listener_fanTimeCheck()
{
	uint8_t fanTime = Model_getFanTime();
	switch(fanTime)
	{
	case CON	:
	if(Button_GetState(&btn_timer)==ACT_RELEASED)
	{
		Sound_Timer();
		fanTime = MIN3;
		Model_setFanTime(fanTime);
		FanTimer_Mode();
	}
	break;
	case MIN3	:
	if(Button_GetState(&btn_timer)==ACT_RELEASED)
	{
		Sound_Timer();
		fanTime = MIN5;
		Model_setFanTime(fanTime);
		FanTimer_Mode();
	}
	break;
	case MIN5	:
	if(Button_GetState(&btn_timer)==ACT_RELEASED)
	{
		Sound_Timer();
		fanTime = MIN7;
		Model_setFanTime(fanTime);
		FanTimer_Mode();
	}
	break;
	case MIN7	:
	if(Button_GetState(&btn_timer)==ACT_RELEASED)
	{
		Sound_Timer();
		fanTime = CON;
		Model_setFanTime(fanTime);
		FanTimer_Mode();
	}
	break;		
	}
}

void Listener_fanTimer_Start()
{
	uint8_t fanRun = Model_getFanTimer_Start();
	switch(fanRun){
		case STOP :
		if(Button_GetState(&btn_start)==ACT_RELEASED)
		{
			Sound_Start();
			fanRun = START;
			Model_setFanTimer_Start(fanRun);
		}
		break;
		case START :
		
		if(Button_GetState(&btn_start)==ACT_RELEASED)
		{
			Sound_Timer();
			fanRun = STOP;
			Model_setFanTimer_Start(fanRun);
		}
		break;
	}
}