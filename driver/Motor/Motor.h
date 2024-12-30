
#ifndef MOTOR_H_
#define MOTOR_H_
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#define MOTOR_ICR	ICR3
#define MOTOR_OCR	OCR3A


//초기화
void Motor_init();


void Motor_change(uint8_t Duty);

void Motor_Run();

void Motor_On();

void Motor_Off();




#endif /* BUZZER_H_ */