#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <time.h>
#include "GA.h"
#include "heap.h"
using namespace std;
void main()
{
	Heap heap;
	GA ga[5];
	srand((unsigned)time(0));

	for (int i = 0; i < 5; i++)
	{
		ga[i].result = rand();
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

