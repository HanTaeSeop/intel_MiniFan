#include "Timer.h"

void Timer0_init() // 1ms overflow interrupty , for FND display
{
	TCCR0 |= ((1<<CS02) | (0<<CS01) | (1<<CS00)); // 128 prescaler
	TIMSK |= (1<<TOIE0);						//TiMSK Timer/Counter0 overflow interrupt enable
	TCNT0 = 130;
}

//Timer/Counter 2 1/64 pre 1ms period interrupt, CTC mode
void Timer2_init()
{
	TCCR2 |= ((0<<CS22) | (1<<CS21) | (1<<CS20)); // 64 prescaler 
	TIMSK |= (1<<OCIE2);						//TiMSK Timer/Counter0 overflow interrupt enable
	//CTC
	TCCR2 |= ((1<<WGM21) | (0<<WGM20));
	OCR2 = 250-1;
}