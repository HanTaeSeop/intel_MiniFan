#include "Presenter.h"

void Presenter_init()
{
	FND_init();
	LCD_init();
}



void Preseter_dispTimerData(uint8_t hour,uint8_t min,uint8_t sec,uint16_t milisec)
{
	static uint16_t prevmilisec = 0xff;
	
	if(milisec == prevmilisec){
		prevmilisec = milisec/10;
		return;
	}
	
	uint16_t clockData = 0;
	uint8_t fanWindData;
	fanWindData = Model_getFanWind();
	char windData[10];
	
	//LCD화면
	switch(fanWindData)
	{
		case OFF :
		strcpy(windData," OFF  ");
		break;
		case WEAK :
		strcpy(windData," WEAK ");
		break;
		case NORMAL :
		strcpy(windData,"NORMAL");
		break;
		case STRONG :
		strcpy(windData,"STRONG");
		break;
	}
	
	char buff1[30];
	
	sprintf(buff1,"MINI FAN");
	LCD_writeStrXY(0,4,buff1);
	sprintf(buff1,"%02d:%02d & %s",min,sec,windData);
	LCD_writeStrXY(1,1,buff1);
	
	//FND화면
	clockData = (min*100) + sec;
	FND_setFndData(clockData);
	
	if(milisec/10 < 50)
	{
	FND_colonOn();
	}
	else
	{
	FND_colonOff();
	}
}