#include "tubu_search.h"
#include "matrix.h"
#include "tubu_search.h"
#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;

#define NG 55


void main()
{
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

	for (int i = 0; i < 30; i++)
	{
		point[i].x = dis[i * 2];
		point[i].y = dis[i * 2 + 1];
	}

	bool stop = false;

	//如何能让输入的size改变所有的size
	Matrix Dis(SIZE, SIZE);
	Matrix Tubu(SIZE, SIZE, ZERO);
	Matrix Delta(SIZE, SIZE, ZERO);



	// 极大化目标
	double result = 0;
	int cnt = 0;
	//渴望水平
	double egar = 0, result_egar = 0;

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = i; j < SIZE; j++)
		{
			if (i == j)
				Dis[i][j] = 0;
			else
				Dis[i][j] = Dis[j][i]=sqrt(i_pow(point[i].x - point[j].x) + i_pow(point[i].y - point[j].y));
		}
	}
	//cout << Dis;
	//while (1);
	//设置初始路径	数字代表顺序
	char* result_vector;
	result_vector = new char[SIZE];

	for (int i = 0; i < SIZE; i++)
	{
		result_vector[i] = i + 1;
	}
	result_vector[4] = 8;
	result_vector[7] = 5;
	//result_vector[0] = 1;//A
	//result_vector[1] = 2;//B
	//result_vector[2] = 3;//C
	//result_vector[3] = 4;//D
	//result_vector[4] = 5;//E


	//计算初始解
	result = cclResult(result_vector, Dis);
	//初始渴望值
	egar = result;
	cout << "初始解：" << result << endl;
	//如果所有解都被禁忌/达到最大搜索次数
	for (uint32_t k = 0; (k<NG && abnormalStop(Tubu)); k++)
	{


		//在未被禁忌的邻域中搜索
		result_egar = opt_2(Delta, Dis, Tubu, result_vector, result);
		//如果满足渴望值，跳出禁忌	
		if (result_egar > egar)
			result_egar = breakTubu(Delta, Dis, Tubu, result_vector, result);


		//更新解向量
		swap(result_vector[getLocationRow()], result_vector[getLocationColum()]);
		//更新解、更新渴望值
		egar = result = result_egar;
		cout << "寻优结果：" << result << endl;
		//更新禁忌表
		updataTubu(Tubu);

	}
	cout << "寻优结果：" << result << endl;
	system("pause");
}