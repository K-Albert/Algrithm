#include "tubu_search.h"
#include "matrix.h"
#include "tubu_search.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

#define NG 15

int dis[10] = { 10, 15, 6, 2, 8, 13, 9, 20, 15, 5 };
void main()
{
	bool stop = false;
	int size = 0;
	cout << "请输入：";
	cin >> size;

	//如何能让输入的size改变所有的size
	Matrix Dis(SIZE, SIZE);
	Matrix Tubu(SIZE, SIZE, ZERO);
	Matrix Delta(SIZE, SIZE, ZERO);



	// 极大化目标
	double result = 0;
	int cnt = 0;
	//渴望水平
	double egar = 0,result_egar=0;

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = i; j < SIZE; j++)
		{
			if (i == j)
				Dis[i][j] = 0;
			else
				Dis[i][j] = Dis[j][i] = dis[cnt++];
		}
	}


	//设置初始路径	数字代表顺序
	char* result_vector;
	result_vector = new char[SIZE];

	
	result_vector[0] = 1;//A
	result_vector[1] = 2;//B
	result_vector[2] = 3;//C
	result_vector[3] = 4;//D
	result_vector[4] = 5;//E


    //计算初始解
	result = cclResult(result_vector, Dis);
	//初始渴望值
	egar = result;
	cout << "初始解："<<result << endl;
	
	//如果所有解都被禁忌/达到最大搜索次数
	for (uint32_t k = 0;( k<NG && abnormalStop(Tubu) ); k++)
	{


		//在未被禁忌的邻域中搜索
		result_egar = opt_2(Delta, Dis, Tubu, result_vector, result);
		//如果满足渴望值，跳出禁忌	
		if (result_egar < egar)
		result_egar = breakTubu(Delta, Dis, Tubu, result_vector, result);

		
		//更新解向量
		swap(result_vector[getLocationRow()], result_vector[getLocationColum()]);
		//更新解、更新渴望值
		egar = result = result_egar;
		//更新禁忌表
		updataTubu(Tubu);

	}	
	cout << "寻优结果："<<result << endl;
	system("pause");
}