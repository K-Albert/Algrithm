#ifndef __KNAPSACK_H
#define __KNAPSACK_H
#include <stdint.h>
#include <iostream>
#include "matrix_vector.h"
#include <vector>
#include "rand.h"
using namespace std;
#define POP_SIZE 30                //种群大小
#define PRO_CROSS 0.5            // 交叉概率（所有的个体都需要相互交叉的，这里的交叉率指交叉时每位交叉发生交叉的可能性）  
#define PRO_MUTATE 0.05            // 变异概率
#define GENERATION_NUM 100        // 繁殖代数

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
	Matrix_Vector& crossOver(Matrix_Vector &pop);//均匀交叉
	Matrix_Vector& mutation(Matrix_Vector & pop);//变异
	int sortBest(vector<double>& fit, double bestFitness);


private:
	int knapsack_num = 0;
	int item_num = 0;
	vector<double> capcity;
	double sumFitness = 0;
};



#endif