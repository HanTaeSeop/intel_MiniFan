#include "GPIO.h"

//GPIO 기능 : DDR 설정 PORT 설정 PIN 설정 (범용)

/* (경우의 수) 
DDR		1.Port		3.0x00 ,	4.|= (1<<0) , 
		2. Pin		5.0x00 ,	6&=~(1<<0)	*/

//전체 포트의 데이터 디렉션 설정
void Gpio_initPort(volatile uint8_t* DDR, uint8_t dir){
	if(dir == OUTPUT){
		*DDR = 0xff;
	}
	else{
		*DDR = 0x00;
	}
} 

//포트중 하나의 핀의 디렉션 설정
void Gpio_initPin(volatile uint8_t* DDR, uint8_t dir, uint8_t pinNum){
	if(dir == OUTPUT)
	{
		*DDR |= (1<<pinNum);
	}
	else
	{
		*DDR &= ~(1<<pinNum);
	}
}

void Gpio_writePort(volatile uint8_t* PORT, uint8_t data){
	*PORT = data;
}

void Gpio_writePin(volatile uint8_t* PORT, uint8_t pinNum, uint8_t state){
	
	if(state == GPIO_PIN_SET){
		*PORT |= (1<<pinNum);
	}
	else{
		*PORT &=~(1<<pinNum);
	}
}

uint8_t Gpio_readPort(volatile uint8_t* PIN)
{
	return *PIN;	
}

uint8_t Gpio_readPin(volatile uint8_t* PIN, uint8_t pinNum){
	return ((*PIN & (1<<pinNum)) != 0);
	//pushed 면 반환값을 0을 받아야 한다 (pull up 저항이어서) 따라서 False값인 0을 return
	
}