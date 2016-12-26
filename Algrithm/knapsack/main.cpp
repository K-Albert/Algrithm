#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <time.h>
#include "rand.h"
#include <stdint.h>
#include <vector>
#include <iterator>
#include <fstream>
#include "matrix_vector.h"
using namespace std;

#define N 6 //物品个数
#define M 10 //背包个数

float data[10][6]
{
	{ 8, 12, 13, 64, 22, 41 },
	{ 8, 12, 13, 75, 22, 41 },
	{ 3, 6, 4, 18, 6, 4 },
	{ 5, 10, 8, 32, 6, 12 },
	{ 5, 13, 8, 42, 6, 20 },
	{ 5, 13, 8, 48, 6, 20 },
	{ 0, 0, 0, 0, 8, 0 },
	{ 3, 0, 4, 0, 8, 0 },
	{ 3, 2, 4, 0, 8, 4 },
	{ 3, 2, 4, 8, 8, 4 },
};

float capicity[] = { 80, 96, 20, 36, 44, 48, 10, 18, 22, 24 };


void main()
{
	int i = 0;
	Matrix_Vector Weight(N,M);
	const char filename[] = "1.txt";
	ofstream o_file;   /* 输出流：将数据从内存输出   其中ofstream是将数据输出到文件，因此对于文件来说是“写”*/
	ifstream i_file;   /*将数据输入到内存，其中ifstream是说输入的数据在文件中，因此对于文件来说是“读”*/

	i_file.open(filename);
	if (i_file.is_open())
	{
		//while (!i_file.eof())//  因为数据是定长，所以较简单。 如果使用判断eof，则会出现最后一个数据读取两次的情况，需特殊处理
		//{
		while (i <= N * M)
		{
			while (i % N)
			{

			}
			//if (i % N)
			//{
			//	i_file >> datain[(int)((i - 1) / 2)];//第一列数据为输入
			//}
			//else
			//{
			//	i_file >> dataout[(int)((i - 1) / 2)];//第二例数据为输出
			//}
			//i++;

		}

		//}
		i_file.close();
	}


}