#ifndef _HEAP_H
#define _HEAP_H

class Heap
{
  public:
	  void heapAdjust(int H[], int s, int lenth);
	  void heapInitial(int H[], int lenth);
	  void heapSort(int H[], int lenth);

	  void heapAdjust(float H[], int s, int lenth);
	  void heapInitial(float H[], int lenth);
	  void heapSort(float H[], int lenth);

};
#endif