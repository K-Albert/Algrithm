#ifndef __KNAPSACK_H
#define __KNAPSACK_H
#include <stdint.h>
#include <iostream>
#include <algorithm>
#include "matrix_vector.h"
#include <vector>
#include "rand.h"
using namespace std;
#define POP_SIZE 200                //��Ⱥ��С
#define PRO_CROSS 0.05          // ������ʣ����еĸ��嶼��Ҫ�໥����ģ�����Ľ�����ָ����ʱÿλ���淢������Ŀ����ԣ�  
#define PRO_MUTATE 0.3            // �������
#define GENERATION_NUM 1000        // ��ֳ����

class  Knapsack
{
public:
	Knapsack(int m, int n){ item_num = n; knapsack_num = m; }
	~Knapsack() = default;
	void setCapcity(vector<double> c){ capcity = c; }
	void initPop(Matrix_Vector& weight, Matrix_Vector& Pop);
	vector<double> cclWeight(Matrix_Vector &weight, vector<double>& pop);
	vector<double> cclFitness(vector<double>&value, Matrix_Vector &pop, Matrix_Vector &weight);
	vector<double> cclFitness(vector<double>&value, Matrix_Vector &pop, Matrix_Vector &weight, int size);//������Ⱥ��Ӧ��
	vector<double> buildWheel(vector<double> & fit);
	int seletIndividual(vector<double>& prob);
	Matrix_Vector crossOver(Matrix_Vector pop);//���Ƚ���
	Matrix_Vector& mutation(Matrix_Vector & pop);//����
	int sortBest(vector<double>& fit, double bestFitness);
	Matrix_Vector& selectNewPop(Matrix_Vector& tmpPop, Matrix_Vector& newpop, Matrix_Vector& pop, Matrix_Vector& r_pop, vector<double>&value, Matrix_Vector &weight);
	Matrix_Vector& selectNewPop(Matrix_Vector& newpop, Matrix_Vector& pop, Matrix_Vector& r_pop, vector<double>&value, Matrix_Vector &weight);
private:
	int knapsack_num = 0;
	int item_num = 0;
	vector<double> capcity;
	double sumFitness = 0;
};

bool cmp(const pair<uint32_t, float> &a, const pair<uint32_t, float> &b);

#endif