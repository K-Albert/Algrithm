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

	//������������size�ı����е�size
	Matrix Dis(SIZE, SIZE);
	Matrix Tubu(SIZE, SIZE, ZERO);
	Matrix Delta(SIZE, SIZE, ZERO);



	// ����Ŀ��
	double result = 0;
	int cnt = 0;
	//����ˮƽ
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
	//���ó�ʼ·��	���ִ���˳��
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


	//�����ʼ��
	result = cclResult(result_vector, Dis);
	//��ʼ����ֵ
	egar = result;
	cout << "��ʼ�⣺" << result << endl;
	//������нⶼ������/�ﵽ�����������
	for (uint32_t k = 0; (k<NG && abnormalStop(Tubu)); k++)
	{


		//��δ�����ɵ�����������
		result_egar = opt_2(Delta, Dis, Tubu, result_vector, result);
		//����������ֵ����������	
		if (result_egar > egar)
			result_egar = breakTubu(Delta, Dis, Tubu, result_vector, result);


		//���½�����
		swap(result_vector[getLocationRow()], result_vector[getLocationColum()]);
		//���½⡢���¿���ֵ
		egar = result = result_egar;
		cout << "Ѱ�Ž����" << result << endl;
		//���½��ɱ�
		updataTubu(Tubu);

	}
	cout << "Ѱ�Ž����" << result << endl;
	system("pause");
}