
#ifndef BUZZER_H_
#define BUZZER_H_
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#define BUZZER_ICR	ICR3
#define BUZZER_OCR	OCR3B

void Buzzer_makeHertz(uint16_t hertz);

void Buzzer_soundOn();

void Buzzer_soundOff();

void Buzzer_init();


#endif /* BUZZER_H_ */