#include "GA.h"
void GA::generate()
{   
}
int GA::seletIndividual()
{
	double p = rand_0_1();
	if (p < probi[0])
		return 0;
	if (p>probi[size - 1])
		return (size - 1);
	for (int i = 1; i < size; i++)
	{
		if (p >= probi[i - 1] && p<probi[i])
			return i;
	}
	return -1;

}
void GA::bulidWheel(Tour &tour)
{
	double pSum = 0.0, p = 0.0,test = 0.0;
	for (int cnt = 0; cnt < size;cnt ++)
	{
		fitness[cnt] = tour.cclResult(cnt);
		cout << fitness[cnt] << endl;
		//sump
		pSum += fitness[cnt];
	}

	//for (int cnt = 0; cnt < size; cnt++)
	//{
	//
	//	probi[cnt] = (1-fitness[cnt] / pSum)/(POINT_SIZE-1);
	//	test += probi[cnt];
	//	cout << probi[cnt]<<endl;

	//}
	//cout << test << endl;
	//while (1);

	for (int cnt = 0; cnt < size; cnt++)
	{
		if (cnt != 0)
			probi[cnt] = (1 - fitness[cnt] / pSum) / (POINT_SIZE - 1) + probi[cnt - 1];
		else
			probi[cnt] = (1 - fitness[cnt] / pSum) / (POINT_SIZE - 1);
	}

}