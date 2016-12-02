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
#define POINT_SIZE 30
#define RESULT_SIZE 60
using namespace std;
bool cmp(const pair<uint32_t, float> &a, const pair<uint32_t, float> &b);
bool cmp(const pair<uint32_t, float> &a, const pair<uint32_t, float> &b)
{
	return a.second > b.second;
}
void main()
{
	Heap heap;
	GA ga[5];
	float a;
	srand((unsigned)time(0));
    
	Matrix_Vector Result(RESULT_SIZE, POINT_SIZE);
	vector<pair<uint32_t, float>> result(POINT_SIZE);
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
	cout << Result;

	while (1);
	




	for (int i = 0; i < 5; i++)
	{
		ga[i].result = rand_0_1();
		ga[i].subscript = i+1;
		cout << ga[i].result << " " << ga[i].subscript << endl;
	}
	heap.heapSort(ga,5);
	for (int i = 0; i < 5; i++)
	{
		cout << ga[i].result <<" "<< ga[i].subscript<< endl;
		
	}

	system("pause");

}


