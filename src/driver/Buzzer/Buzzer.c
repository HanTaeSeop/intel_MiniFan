#include "Buzzer.h"

void Buzzer_makeHertz(uint16_t hertz)
{
	if (hertz < 100) hertz = 100;
	else if (hertz > 5000) hertz = 5000;
	BUZZER_ICR = (250000 / hertz) -1; //1 * x Hz, Top value
	BUZZER_OCR = BUZZER_ICR/2; //Duty cycle 50%
}

void Buzzer_soundOn()
{
	TCCR3A |= (1<<COM3B1) | (0<<COM3B0); // non-inverting mode
}

void Buzzer_soundOff()
{
	TCCR3A &= ~((1<<COM3B1) | (1<<COM3B0));
}

void Buzzer_init()
{
	TCCR3B |= ((0<<CS32) | (1<<CS31) | (1<<CS30)); //Pre 1/64
	TCCR3A |= (1<<WGM31)|(0 <<WGM30);
	TCCR3B |= (1<<WGM33)|(1<<WGM32);
}