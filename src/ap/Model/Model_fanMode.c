#include "Model_fanMode.h"

uint8_t fanMode;

uint8_t Model_getFanMode()
{
	return fanMode;
}

void Model_setFanMode(uint8_t data)
{
	fanMode = data;
}
