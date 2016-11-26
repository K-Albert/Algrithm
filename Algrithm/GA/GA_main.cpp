#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <random>
#include "GA.h"
#include "heap.h"
using namespace std;
void main()
{
	Heap heap;
	float a[5] = { 9.1, 4.1, 8.9, 6.7, 6.5 };
	heap.heapSort(a, 5);
	//heapInitial(a, 5);
	for (int i = 0; i < 5; i++)
	{
		cout << a[i] << endl;
	}
	system("pause");

}
bool compare(int a, int b)
{
	return a > b;//ÉýÐò
}

