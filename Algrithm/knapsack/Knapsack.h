#ifndef __KNAPSACK_H
#define __KNAPSACK_H
#include <stdint.h>
#include <iostream>
#include "matrix_vector.h"
#include <vector>
#include "rand.h"
using namespace std;
#define POP_SIZE 30                //��Ⱥ��С
#define PRO_CROSS 0.5            // ������ʣ����еĸ��嶼��Ҫ�໥����ģ�����Ľ�����ָ����ʱÿλ���淢������Ŀ����ԣ�  
#define PRO_MUTATE 0.05            // �������
#define GENERATION_NUM 100        // ��ֳ����

class  Knapsack
{
public:
	Knapsack(int m, int n){ item_num = n; knapsack_num = m; }
	~Knapsack() = default;
	void setCapcity(vector<double> c){ capcity = c; }
	void initPop(Matrix_Vector& weight, Matrix_Vector& Pop);
	vector<double> cclWeight(Matrix_Vector &weight, vector<double>& pop);
	vector<double> cclFitness(vector<double>&value, Matrix_Vector &pop, Matrix_Vector &weight);
	vector<double> buildWheel(vector<double> & fit);
	int seletIndividual(vector<double>& prob);
	Matrix_Vector& crossOver(Matrix_Vector &pop);//���Ƚ���
	Matrix_Vector& mutation(Matrix_Vector & pop);//����
	int sortBest(vector<double>& fit, double bestFitness);


private:
	int knapsack_num = 0;
	int item_num = 0;
	vector<double> capcity;
	double sumFitness = 0;
};



#endif