#include "rand.h"
#include <stdlib.h>

float rand_0_1() //产生0-1之间的随机数
{
	float temp = 0;
	temp = rand() % 10001;
	return (float)(temp / 10000);
}