#include "Motor.h"

void Motor_init()
{
	TCCR3B |= ((0<<CS32) | (1<<CS31) | (1<<CS30)); //Pre 1/64
	TCCR3A |= (1<<WGM31)|(0 <<WGM30);
	TCCR3B |= (1<<WGM33)|(1<<WGM32);
	DDRE |= (1<<3);
}


void Motor_change(uint8_t Duty)
{
	MOTOR_ICR = (250000 / 1000) -1; //1 * x Hz, Top value
	MOTOR_OCR = MOTOR_ICR/Duty; //Duty cycle 50%
}
void Motor_Run()
{
	 Motor_change(4);
	_delay_ms(100);
	TCNT3 = 0;
}
void Motor_On()
{
	TCCR3A |= (1<<COM3A1) | (0<<COM3A0); // non-inverting mode
}

void Motor_Off()
{
	TCCR3A &= ~((1<<COM3A1) | (1<<COM3A0));
}

