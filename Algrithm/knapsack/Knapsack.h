#ifndef __KNAPSACK_H
#define __KNAPSACK_H
#include <stdint.h>
#include <iostream>
#include <algorithm>
#include "matrix_vector.h"
#include <vector>
#include "rand.h"
using namespace std;
#define POP_SIZE 300                //种群大小
#define PRO_CROSS 0.8          // 交叉概率（所有的个体都需要相互交叉的，这里的交叉率指交叉时每位交叉发生交叉的可能性）  
#define PRO_MUTATE 0.9            // 变异概率
#define GENERATION_NUM 1000        // 繁殖代数
#define PROPOTIY 0.955

#define MUTATE_UP 0.3
#define MUTATE_DOWN 0.7
class  Knapsack
{
public:
	Knapsack(int m, int n){ item_num = n; knapsack_num = m; }
	~Knapsack() = default;
	void setCapcity(vector<double> c){ capcity = c; }
	void initPop(Matrix_Vector& weight, Matrix_Vector& Pop);
	vector<double> cclWeight(Matrix_Vector &weight, vector<double>& pop);
	vector<double> Knapsack::cclWeight(Matrix_Vector &weight, vector<double>& pop, int size); //计算背包重量
	vector<double> cclFitness(vector<double>&value, Matrix_Vector &pop, Matrix_Vector &weight);
	vector<double> cclFitness(vector<double>&value, Matrix_Vector &pop, Matrix_Vector &weight, int size);//计算种群适应度

	vector<double> buildWheel(vector<double> & fit);
	int seletIndividual(vector<double>& prob);
	Matrix_Vector crossOver(Matrix_Vector pop);//均匀交叉
	Matrix_Vector& mutation(Matrix_Vector & pop);//变异
	int sortBest(vector<double>& fit, double bestFitness);
	Matrix_Vector& selectNewPop(Matrix_Vector& tmpPop, Matrix_Vector& newpop, Matrix_Vector& pop, Matrix_Vector& r_pop, vector<double>&value, Matrix_Vector &weight);
	Matrix_Vector& selectNewPop(Matrix_Vector& newpop, Matrix_Vector& pop, Matrix_Vector& r_pop, vector<double>&value, Matrix_Vector &weight);

	double cclSim(vector<double> &par1, vector<double> &par2);

	Matrix_Vector& bornChild(Matrix_Vector& childPopulation, Matrix_Vector& Population, vector<double> Fitness, vector<double> &value, Matrix_Vector& weight, Matrix_Vector & pop);

	Matrix_Vector& bornChild2(Matrix_Vector& childPopulation, Matrix_Vector& Population, vector<double> Fitness, vector<double> &value, Matrix_Vector& weight, Matrix_Vector & pop);
	
	Matrix_Vector& bornChild3(Matrix_Vector& childPopulation, Matrix_Vector& Population, vector<double> Fitness, vector<double> &value, Matrix_Vector& weight, Matrix_Vector & pop);
	void setMutate(float x){ pro_mutate = x; };
	void setSim(float x){ pro_sim = x; };
private:
	int knapsack_num = 0;
	int item_num = 0;
	vector<double> capcity;
	double sumFitness = 0;
	float pro_mutate=0;
	float pro_sim = 0;
};

bool cmp(const pair<uint32_t, float> &a, const pair<uint32_t, float> &b);

#endif