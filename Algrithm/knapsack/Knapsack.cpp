#include "Knapsack.h"

vector<double> Knapsack::cclWeight(Matrix_Vector &weight, vector<double>& pop) //计算背包重量
{
	vector<double> popSumWeight(knapsack_num) ;

	for (int i = 0; i < knapsack_num; i++)
	{
		for (int j = 0; j < item_num; j++)
		{
			popSumWeight[i] += pop[j] * weight[i][j];   // pop  为0/1  weight为物品重量
		}
	}
	return popSumWeight;
}
void Knapsack::initPop(Matrix_Vector &weight, Matrix_Vector& Pop)   //初始化种群
{
	vector<double> tmpWeight ;
	bool   isPop = false;
	int i = 0;
	while ( i < POP_SIZE)
	{
		for (int j = 0; j < item_num; j++)
		{
			Pop[i][j] = rand() % 2;                      //产生0/1
		}
		/*
	   tmpWeight = cclWeight(weight, Pop[i]);
		for (int k = 0; k < knapsack_num; k++)           //刨除超重的
		{
			if (tmpWeight[k]  > capcity[k])
			{
				isPop = false;
				break;
			}
			isPop = true;
		}
		if (isPop)*/
      i++;
	}
	//cout << Pop;
}
vector<double> Knapsack::cclFitness(vector<double>&value, Matrix_Vector &pop, Matrix_Vector &weight)//计算种群适应度
{
	vector<double> fit(POP_SIZE);
	vector<double> tmpWeight;

	
	for (int i = 0; i < POP_SIZE; i++)
	{

		for (int j = 0; j < item_num; j++)
		{
			fit[i] += pop[i][j] * value[j];
		}
		tmpWeight = cclWeight(weight, pop[i]);
		for (int k = 0; k < knapsack_num; k++)           //超重了适应度为0
		{
			if (tmpWeight[k]  > capcity[k])
			{
				fit[i] = 0;
				break;
			}

		}
		sumFitness += fit[i]; //总适应度，为轮盘赌作准备
	}
	return fit;
}

vector<double> Knapsack::buildWheel(vector<double> & fit) //初始化轮盘
{
	vector<double> prob(POP_SIZE);
	prob[0] = fit[0] / sumFitness;
	for (int i = 1; i < POP_SIZE; i++)
	{
		prob[i] = prob[i - 1] + fit[i] / sumFitness;
	}
	return prob;
}

int Knapsack::seletIndividual(vector<double>& prob) //轮盘赌选择个体
{
	double p = rand_0_1(); //生成0~1之间的随机数
	if (p < prob[0]) return 0;
	if (p >= prob[POP_SIZE - 1]) return (POP_SIZE - 1);
	for (int i = 1; i < POP_SIZE; i++)
	{
		if ((p >= prob[i - 1]) && (p < prob[i])) return i;
	}
	return -1;
}
Matrix_Vector& Knapsack::crossOver(Matrix_Vector &pop)//群体交叉
{
	for (int i = 0; i < POP_SIZE; i = i + 2)
	{
		for (int j = 0; j < item_num; j++)
		{
			if (rand_0_1() < PRO_CROSS)///////////////////////////大于还是小于？
			{
				int tmp = pop[i][j];
				pop[i][j] = pop[i + 1][j];
				pop[i + 1][j] = tmp;
			}
		}
	}
	return pop;
}
Matrix_Vector& Knapsack:: mutation(Matrix_Vector & pop)//变异
{

	for (int i = 0; i<POP_SIZE; i++)   //遍历，如果大于变异率就变异
	{
		for (int j = 0; j<item_num; j++)
		{
			if (rand_0_1() > PRO_MUTATE)
			{
				pop[i][j] == 0 ? pop[i][j] = 1 : pop[i][j] = 0;
			}
		}
	}
	return pop;

}
int Knapsack::sortBest(vector<double>& fit, double bestFitness)
{
	int best = 0;
	bool flag = false;
	for (int i = 0; i < POP_SIZE; i++)
	{
		if (fit[i] > bestFitness)
		{
			bestFitness = fit[i];
			best = i;
			flag = true;
		}		
	}
	if (flag) 	return best;
	return -1;
}
