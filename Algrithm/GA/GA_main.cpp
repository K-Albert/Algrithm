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
#define RESULT_SIZE 5
using namespace std;
void main()
{
	Heap heap;
	GA ga[5];
	float a;
	srand((unsigned)time(0));
    
	vector<pair<uint32_t,float>> result(RESULT_SIZE);
	for (int i = 0; i < RESULT_SIZE; i++)
	{
		result[i].first = i + 1;
		result[i].second = rand_0_1();
		cout << result[i].second << " " << result[i].first << endl;
	}
	heap.heapSort(result, RESULT_SIZE);
	for (int i = 0; i < RESULT_SIZE; i++)
	{
		cout <<result[i].second << " " << result[i].first << endl;
	}
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
bool compare(int a, int b)
{
	return a > b;//ÉýÐò
}

