#include "tubu_search.h"
#include "matrix.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

int dis[10] = { 10, 15, 6, 2, 8, 13, 9, 20, 15, 5 };
void main()
{
	Matrix Dis(5, 5);
	int cnt = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (i == j)
				Dis[i][j] = 0;
			else
				Dis[i][j] = Dis[j][i] = dis[cnt++];
		}
	}

	char size = 0;
	size = A(5, 2);
	char *tabu;
	tabu = new char[size];
	for (int i = 0; i < size; i++)
	{
		tabu[i] = 0;
	}





	system("pause");
}
uint32_t A(uint32_t m,uint32_t n)
{
	uint32_t result=1, cnt = 0;
	cnt =  n ;
	for (uint32_t i = 0; i < cnt; i++)
	{
		result*=(m - i);
	}
	return result;
}
uint32_t C(uint32_t m, uint32_t n)
{
	uint32_t result=0;

	result = A(m, n) / A(n, n);
	return result;
}