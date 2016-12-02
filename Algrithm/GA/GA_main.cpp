#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <time.h>
#include "GA.h"
#include "heap.h"
#include "rand.h"
#include <stdint.h>
#include <vector>
#include <iterator>
#include "matrix_vector.h"
#include "tour.h"

#include "point.h"

using namespace std;
bool cmp(const pair<uint32_t, float> &a, const pair<uint32_t, float> &b);
bool cmp(const pair<uint32_t, float> &a, const pair<uint32_t, float> &b)
{
	return a.second > b.second;
}
void main()
{
	Heap heap;

  //  srand((unsigned)time(0));
	//初始化距离
	int dis[60] = {
		41, 94, 37, 84, 54, 67, 25, 62,
		7, 64, 2, 99, 68, 58, 71, 44,
		54, 62, 83, 69, 64, 60, 18, 54,
		22, 60, 83, 46, 91, 38, 25, 38,
		24, 42, 58, 69, 71, 71, 74, 78,
		87, 76, 18, 40, 13, 40, 82, 7,
		62, 32, 58, 35, 45, 21, 41, 26,
		44, 35, 4, 50 };
	Point point[30];
	Matrix_Vector Dis(POINT_SIZE, POINT_SIZE);
	Matrix_Vector Result(RESULT_SIZE, POINT_SIZE);
	vector<pair<uint32_t, float>> result(POINT_SIZE);
	Tour tour;
	GA ga[5];

	//计算点与点之间的距离
	for (int i = 0; i < 30; i++)
	{
		point[i].x = dis[i * 2];
		point[i].y = dis[i * 2 + 1];
	}
	for (int i = 0; i < POINT_SIZE; i++)
	{
		for (int j = i; j < POINT_SIZE; j++)
		{
			if (i == j)
				Dis[i][j] = 0;
			else
				Dis[i][j] = Dis[j][i] = sqrt(point[i].i_pow(point[i].x - point[j].x) + point[i].i_pow(point[i].y - point[j].y));
		}
	}
	//生成解空间
	for (int i = 0; i < RESULT_SIZE; i++)
	{
		for (int count = 0; count < POINT_SIZE; count++)
		{
			result[count].first = count + 1;
			result[count].second = rand_0_1();
		}
		//heap.heapSort(result, POINT_SIZE);//堆排序 随机产生一个解
		sort(result.begin(), result.end(), cmp);//STL库自带算法

		for (int j = 0; j < POINT_SIZE; j++)//放入解空间
		{
			Result[i][j] = result[j].first;
		}
	}
	
	//适值
	vector<double> fitness(RESULT_SIZE);
	vector<double> proi(RESULT_SIZE);
	double pSum = 0.0,p=0.0;
	for (int cnt = 0; cnt < RESULT_SIZE;cnt++)
	{
		fitness[cnt] = tour.cclResult(Result[cnt], Dis);
		//sump
		pSum += fitness[cnt];
	}
	for (int cnt = 0; cnt < RESULT_SIZE; cnt++)
	{
		if (cnt != 0)
			proi[cnt] = fitness[cnt] / pSum + proi[cnt - 1];
		else
			proi[cnt] = fitness[cnt] / pSum;
	}

	system("pause");

}

int seletIndividual(vector<double> &proi)
{
	double p = rand_0_1();
	if (p < proi[0])
		return 0;
	if (p>proi[RESULT_SIZE - 1])
		return (RESULT_SIZE - 1);
	for (int i = 1; i < RESULT_SIZE ; i++)
	{
		if (p>=proi[i - 1] && p<proi[i])
			return i;
	}
	return -1;
}

