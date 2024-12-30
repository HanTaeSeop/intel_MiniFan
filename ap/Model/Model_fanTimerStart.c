#include "Model_fanTimerStart.h"

uint8_t fanStartCheck;

uint8_t Model_getFanTimer_Start()
{
	return fanStartCheck;
}

void Model_setFanTimer_Start(uint8_t data)
{
	fanStartCheck = data;
}
