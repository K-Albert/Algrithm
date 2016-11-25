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
	cout << "�����룺";
	cin >> size;

	//������������size�ı����е�size
	Matrix Dis(SIZE, SIZE);
	Matrix Tubu(SIZE, SIZE, ZERO);
	Matrix Delta(SIZE, SIZE, ZERO);



	// ����Ŀ��
	double result = 0;
	int cnt = 0;
	//����ˮƽ
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


	//���ó�ʼ·��	���ִ���˳��
	char* result_vector;
	result_vector = new char[SIZE];

	
	result_vector[0] = 1;//A
	result_vector[1] = 2;//B
	result_vector[2] = 3;//C
	result_vector[3] = 4;//D
	result_vector[4] = 5;//E


    //�����ʼ��
	result = cclResult(result_vector, Dis);
	//��ʼ����ֵ
	egar = result;
	cout << "��ʼ�⣺"<<result << endl;
	
	//������нⶼ������/�ﵽ�����������
	for (uint32_t k = 0;( k<NG && abnormalStop(Tubu) ); k++)
	{


		//��δ�����ɵ�����������
		result_egar = opt_2(Delta, Dis, Tubu, result_vector, result);
		//����������ֵ����������	
		if (result_egar < egar)
		result_egar = breakTubu(Delta, Dis, Tubu, result_vector, result);

		
		//���½�����
		swap(result_vector[getLocationRow()], result_vector[getLocationColum()]);
		//���½⡢���¿���ֵ
		egar = result = result_egar;
		//���½��ɱ�
		updataTubu(Tubu);

	}	
	cout << "Ѱ�Ž����"<<result << endl;
	system("pause");
}