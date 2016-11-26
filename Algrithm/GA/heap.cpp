#include "heap.h"

void Heap::heapAdjust(int H[], int s, int lenth)
{
	int temp = 0, child = 0;
	temp = H[s];

	child = 2 * s + 1;
	if (child <lenth)
	{
		if ((child + 1) < lenth && (H[child + 1] < H[child]))
		{
			++child;
		}

		if (H[s] > H[child])
		{
			H[s] = H[child];
			s = child;
			child = 2 * s + 1;
		}
		H[s] = temp;
	}

}

void Heap::heapInitial(int H[], int lenth)
{
	for (int i = (lenth - 1) / 2; i >= 0; --i)
	{
		heapAdjust(H, i, lenth);
	}
}

void Heap::heapSort(int H[], int lenth)
{
	heapInitial(H, lenth);
	for (int i = lenth - 1; i > 0; i--)
	{
		int temp = H[i];
		H[i] = H[0];
		H[0] = temp;
		heapAdjust(H, 0, i);
	}
}



void Heap::heapAdjust(float H[], int s, int lenth)
{
	int child = 0;
	float temp = 0;
	temp = H[s];

	child = 2 * s + 1;
	if (child <lenth)
	{
		if ((child + 1) < lenth && (H[child + 1] < H[child]))
		{
			++child;
		}

		if (H[s] > H[child])
		{
			H[s] = H[child];
			s = child;
			child = 2 * s + 1;
		}
		H[s] = temp;
	}

}

void Heap::heapInitial(float H[], int lenth)
{
	for (int i = (lenth - 1) / 2; i >= 0; --i)
	{
		heapAdjust(H, i, lenth);
	}
}

void Heap::heapSort(float H[], int lenth)
{
	heapInitial(H, lenth);
	for (int i = lenth - 1; i > 0; i--)
	{
		float temp = H[i];
		H[i] = H[0];
		H[0] = temp;
		heapAdjust(H, 0, i);
	}
}