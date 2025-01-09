#include "LCD.h"


void GPIO_init()
{
	Gpio_initPin(&LCD_CRL_DDR,OUTPUT,LCD_RS);
	Gpio_initPin(&LCD_CRL_DDR,OUTPUT,LCD_RW);
	Gpio_initPin(&LCD_CRL_DDR,OUTPUT,LCD_E);
	Gpio_initPort(&LCD_DATA_DDR,OUTPUT);
}

void LCD_init()
{
	GPIO_init();
	_delay_ms(15);
	LCD_writeCmdData(LCD_8BIT_FUNCTION_SET);
	_delay_ms(5);
	LCD_writeCmdData(LCD_8BIT_FUNCTION_SET);
	_delay_ms(1);
	LCD_writeCmdData(LCD_8BIT_FUNCTION_SET);
	LCD_writeCmdData(LCD_8BIT_FUNCTION_SET);
	LCD_writeCmdData(LCD_DISPLAY_OFF);
	LCD_writeCmdData(LCD_DISPLAY_CLEAR);
	LCD_writeCmdData(LCD_ENTRY_MODE_SET);
	LCD_writeCmdData(LCD_DISPLAY_ON);
}


void LCD_cmdMode()
{
	//LCD_CRL_PORT &= ~(1<<LCD_RS);
	Gpio_writePin(&LCD_CRL_PORT,LCD_RS,GPIO_PIN_RESET);
}

void LCD_charMode()
{
	//LCD_CRL_PORT |= (1<<LCD_RS);
	Gpio_writePin(&LCD_CRL_PORT,LCD_RS,GPIO_PIN_SET);
}

void LCD_writeMode()
{
	//LCD_CRL_PORT &= ~(1<<LCD_RW);
	Gpio_writePin(&LCD_CRL_PORT,LCD_RW,GPIO_PIN_RESET);
	
}

void LCD_enableHigh()
{
	//LCD_CRL_PORT |= (1<<LCD_E);
	Gpio_writePin(&LCD_CRL_PORT,LCD_E,GPIO_PIN_SET);
	_delay_ms(1); //LCD 동작이 느려서
}

void LCD_enableLow()
{
	//LCD_CRL_PORT &= ~(1<<LCD_E);
	Gpio_writePin(&LCD_CRL_PORT,LCD_E,GPIO_PIN_RESET);
	_delay_ms(1);
}

void LCD_writeByte(uint8_t data)
{
	Gpio_writePort(&LCD_DATA_PORT,data);
}


//MCU -> LCD 명령어 보낼경우
void LCD_writeCmdData(uint8_t data)
{
	LCD_cmdMode(); // RS핀 0으로
	LCD_writeMode(); //Rw핀 0으로
	LCD_enableHigh();
	LCD_writeByte(data); //데이터 write 과정
	LCD_enableLow();
	
}

//MCU -> LCD Data를 보낼 경우
void LCD_writeCharData(uint8_t data)
{
	LCD_charMode(); // RS핀 1으로
	LCD_writeMode(); //Rw핀 0으로
	LCD_enableHigh();
	LCD_writeByte(data); //데이터 write 과정
	LCD_enableLow();
}
void LCD_writeString(char *str)
{
	for(int i=0; str[i]; i++)
	{
		LCD_writeCharData(str[i]);
	}
}

void LCD_gotoXY(uint8_t row, uint8_t col)
{
	col%=  16 ; row %= 2;
	uint8_t lcdregisterAddress = (0x40 *row) +col;
	uint8_t command = 0x80 +lcdregisterAddress;
	LCD_writeCmdData(command);
}

void LCD_writeStrXY(uint8_t row,uint8_t col,char *str)
{
	LCD_gotoXY(row,col);
	LCD_writeString(str);
}

void LCD_clearDisplay()
{
	LCD_writeCmdData(LCD_DISPLAY_CLEAR);
}