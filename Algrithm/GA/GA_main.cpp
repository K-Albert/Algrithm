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
#define SELECT_INDIVIDUAL_ERROR 1

#define INTERSECTP 0.9
using namespace std;

void main()
{
	Heap heap;

   // srand((unsigned)time(0)); //真随机还是伪随机
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
	Tour tour;
	GA ga(POINT_SIZE);
	int individual;

	//设定坐标点
	for (int i = 0; i < 30; i++)
	{
		point[i].x = dis[i * 2];
		point[i].y = dis[i * 2 + 1];
	}
	//计算点与点之间的距离
	tour.cclDis(point);
	//生成解空间
	tour.resultSpace();	
	//轮盘赌概率计算
	ga.bulidWheel(tour);
	vector<double> test(RESULT_SIZE);
	for (int i = 0; i < RESULT_SIZE; i++)
	{
		try
		{
			individual = ga.seletIndividual();
			if (individual == -1)
				throw "error";
		}
		catch (char *str)
		{
			cout << str<<endl;
		}
		tour.cclnewPoP(individual);
		test[i] = individual;
		cout << test[i]<<endl;
	}

	system("pause");

}

