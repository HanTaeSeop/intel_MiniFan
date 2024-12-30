#include "Model_Fan_Sound.h"

	
void Fansound_init()
{
	Buzzer_init();
	DDRE |= (1<<4);
	Sound_start();
}

void Sound_start()
{
	Buzzer_soundOn();
	Buzzer_makeHertz(1046);
	_delay_ms(100);
	TCNT3 = 0;
	Buzzer_makeHertz(1318);
	_delay_ms(100);
	TCNT3 = 0;
	Buzzer_makeHertz(1567);
	_delay_ms(100);
	TCNT3 = 0;
	Buzzer_makeHertz(1046);
	_delay_ms(100);
	TCNT3 = 0;
	Buzzer_soundOff();
}

void Sound_Auto()
{
	Buzzer_soundOn();
	Buzzer_makeHertz(1567);
	_delay_ms(100);
	TCNT3 = 0;
	Buzzer_makeHertz(1046);
	_delay_ms(100);
	TCNT3 = 0;
	Buzzer_makeHertz(1567);
	_delay_ms(100);
	TCNT3 = 0;
	Buzzer_soundOff();
}

void Sound_Mannual()
{
	Buzzer_soundOn();
	Buzzer_makeHertz(1046);
	_delay_ms(100);
	TCNT3 = 0;
	Buzzer_makeHertz(1567);
	_delay_ms(100);
	TCNT3 = 0;
	Buzzer_makeHertz(1046);
	_delay_ms(100);
	TCNT3 = 0;
	Buzzer_soundOff();
}

void Sound_Wind()
{
	Buzzer_soundOn();
	Buzzer_makeHertz(1046);
	_delay_ms(100);
	TCNT3 = 0;
	Buzzer_soundOff();
}

void Sound_Timer()
{
	Buzzer_soundOn();
	Buzzer_makeHertz(1174);
	_delay_ms(100);
	Buzzer_soundOff();
}

void Sound_Start()
{
	Buzzer_soundOn();
	Buzzer_makeHertz(1046);
	_delay_ms(100);
	Buzzer_makeHertz(1174);
	_delay_ms(100);
	Buzzer_makeHertz(1318);
	_delay_ms(100);
	Buzzer_soundOff();
}

void Sound_End()
{
	Buzzer_soundOn();
	Buzzer_makeHertz(1318);
	_delay_ms(100);
	Buzzer_makeHertz(1174);
	_delay_ms(100);
	Buzzer_makeHertz(1046);
	_delay_ms(100);
	Buzzer_soundOff();
}