#include "Model_fanWind.h"

uint8_t fanWind;

uint8_t Model_getFanWind()
{
	return fanWind;
}

void Model_setFanWind(uint8_t data)
{
	fanWind = data;
}
