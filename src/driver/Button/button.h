
#ifndef BUTTON_H_
#define BUTTON_H_

#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/io.h>
#include "../../Peri/GPIO/GPIO.h"

enum{PUSHED,RELEASED};
enum{ACT_PUSHED,ACT_RELEASED,ACT_NONE};

typedef struct _button  //typedef 는 별칭으로 호출명을 정의하기위한 코드
{
	volatile uint8_t* DDR; //volatile 은 무슨의미인지 찾아보기
	volatile uint8_t* PIN;
	uint8_t pinNum;
	uint8_t prevState;
	//port
	//pin num
	//static prevState
}button_t; //구조체 선언을 하면 button_t = btnNext; = int a; 와 구조적으로 같음

void Button_init(button_t *btn, volatile uint8_t* ddr, volatile uint8_t* pin, uint8_t pinNum);
uint8_t Button_GetState(button_t* btn);
void clock_exe();

#endif /* BUTTON_H_ */