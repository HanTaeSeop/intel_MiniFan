#include "apMain.h"

FILE UARTMODE = FDEV_SETUP_STREAM(UART0_Transmit, NULL,_FDEV_SETUP_WRITE);
//interrupt
ISR(TIMER0_OVF_vect)
{
	FND_ISR_Process();
	TCNT0=130;
}

ISR(TIMER2_COMP_vect)
{
	static uint8_t data;
	data = Model_getFanTimer_Start();
	if(data == STOP) return;
	
	FanTimer_decMilisec();
}

ISR(USART0_RX_vect)
{
	UART0_ISR_Process();
}

void apMain_init()
{
		
		//Listner initialize
		Listener_init();
		
		//Model initialize
		Model_setFanMode(MANNUAL);
		Model_setFanWind(OFF);
		Model_setFanTime(CON);
		Model_setFanTimer_Start(STOP);
		Fansound_init();
		
		//service initialize
		Fan_autoInit();
		FanTimer_init();
		
		//presenter initialize
		Presenter_init();
		
		//driver initialize
		Motor_init();
		
		//peri init
		Timer0_init();
		Timer2_init();
		UART0_init();
		//global iterrupt
		sei();
		stdout = &UARTMODE;
}

void apMain_run()
{
	//Listener ON
	Listener_fanModeCheck();
	Listener_fanWindCheck();
	Listener_fanTimeCheck();
	Listener_fanTimer_Start();
	
	//Service ON
	Fan_mannualRun();
	FanTimer_disp();
	Fan_autoRun();
	FanUart0_run();
	
	//driver ON
	Motor_On();
}