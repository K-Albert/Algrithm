#include "rand.h"
#include <stdlib.h>

float rand_0_1() //����0-1֮��������
{
	float temp = 0;
	temp = rand() % 10001;
	return (float)(temp / 10000);
}