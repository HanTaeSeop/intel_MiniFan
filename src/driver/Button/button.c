#include "button.h" //button.h를 포함한다는뜻 , 구현한건 .c파일에


// 버튼 초기화 함수
void Button_init(button_t *btn, volatile uint8_t* ddr, volatile uint8_t* pin, uint8_t pinNum)
{
	btn->DDR = ddr;
	btn->PIN = pin;
	btn->pinNum = pinNum;
	btn->prevState = 1;  //함수에 전달받은 첫번째 매개변수
	
	Gpio_initPin(btn->DDR,INPUT,btn->pinNum);
	
}

uint8_t Button_GetState(button_t* btn)
{
	
	//uint8_t curState = *btn->PIN & (1<<btn->pinNum);
	uint8_t curState = Gpio_readPin(btn->PIN, btn->pinNum);
	if((curState == 0) && (btn->prevState == 1))
	{
		_delay_ms(10); //debouncing code
		btn->prevState = PUSHED;
		return ACT_PUSHED;
	}
	
	else if((curState != 0) && (btn->prevState == 0))
	{
		_delay_ms(10);
		btn->prevState = RELEASED;
		return ACT_RELEASED;
	}
	return ACT_NONE;
}