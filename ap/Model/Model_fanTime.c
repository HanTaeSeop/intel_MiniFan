#include "Model_fanTime.h"

uint8_t fanTime;

uint8_t Model_getFanTime()
{
	return fanTime;
}

void Model_setFanTime(uint8_t data)
{
	fanTime = data;
}