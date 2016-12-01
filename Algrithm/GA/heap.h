#ifndef _HEAP_H
#define _HEAP_H
#include "GA.h"
#include <vector>
#include <stdint.h>
using namespace std;

class Heap
{
  public:
	  void heapAdjust(int H[], int s, int lenth);
	  void heapInitial(int H[], int lenth);
	  void heapSort(int H[], int lenth);

	  void heapAdjust(float H[], int s, int lenth);
	  void heapInitial(float H[], int lenth);
	  void heapSort(float H[], int lenth);

	  void heapAdjust(GA H[], int s, int lenth);
	  void heapInitial(GA H[], int lenth);
	  void heapSort(GA H[], int lenth);

	  void heapAdjust(vector<pair<uint32_t, float>> &H, int s, int lenth);
	  void heapInitial(vector<pair<uint32_t, float>> &H, int lenth);
	  void heapSort(vector<pair<uint32_t, float>> &H, int lenth);

};
#endif