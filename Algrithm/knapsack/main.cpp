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

#define N 6 //��Ʒ����
#define M 10 //��������

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
	ofstream o_file;   /* ������������ݴ��ڴ����   ����ofstream�ǽ�����������ļ�����˶����ļ���˵�ǡ�д��*/
	ifstream i_file;   /*���������뵽�ڴ棬����ifstream��˵������������ļ��У���˶����ļ���˵�ǡ�����*/

	i_file.open(filename);
	if (i_file.is_open())
	{
		//while (!i_file.eof())//  ��Ϊ�����Ƕ��������Խϼ򵥡� ���ʹ���ж�eof�����������һ�����ݶ�ȡ���ε�����������⴦��
		//{
		while (i <= N * M)
		{
			while (i % N)
			{

			}
			//if (i % N)
			//{
			//	i_file >> datain[(int)((i - 1) / 2)];//��һ������Ϊ����
			//}
			//else
			//{
			//	i_file >> dataout[(int)((i - 1) / 2)];//�ڶ�������Ϊ���
			//}
			//i++;

		}

		//}
		i_file.close();
	}


}