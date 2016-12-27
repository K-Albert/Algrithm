#include "Knapsack.h"

vector<double> Knapsack::cclWeight(Matrix_Vector &weight, vector<double>& pop) //���㱳������
{
	vector<double> popSumWeight(knapsack_num) ;

	for (int i = 0; i < knapsack_num; i++)
	{
		for (int j = 0; j < item_num; j++)
		{
			popSumWeight[i] += pop[j] * weight[i][j];   // pop  Ϊ0/1  weightΪ��Ʒ����
		}
	}
	return popSumWeight;
}
void Knapsack::initPop(Matrix_Vector &weight, Matrix_Vector& Pop)   //��ʼ����Ⱥ
{
	vector<double> tmpWeight ;
	bool   isPop = false;
	int i = 0;
	while ( i < POP_SIZE)
	{
		for (int j = 0; j < item_num; j++)
		{
			Pop[i][j] = rand() % 2;                      //����0/1
		}
		/*
	   tmpWeight = cclWeight(weight, Pop[i]);
		for (int k = 0; k < knapsack_num; k++)           //�ٳ����ص�
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
vector<double> Knapsack::cclFitness(vector<double>&value, Matrix_Vector &pop, Matrix_Vector &weight)//������Ⱥ��Ӧ��
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
		for (int k = 0; k < knapsack_num; k++)           //��������Ӧ��Ϊ0
		{
			if (tmpWeight[k]  > capcity[k])
			{
				fit[i] = 0;
				break;
			}

		}
		sumFitness += fit[i]; //����Ӧ�ȣ�Ϊ���̶���׼��
	}
	return fit;
}

vector<double> Knapsack::buildWheel(vector<double> & fit) //��ʼ������
{
	vector<double> prob(POP_SIZE);
	prob[0] = fit[0] / sumFitness;
	for (int i = 1; i < POP_SIZE; i++)
	{
		prob[i] = prob[i - 1] + fit[i] / sumFitness;
	}
	return prob;
}

int Knapsack::seletIndividual(vector<double>& prob) //���̶�ѡ�����
{
	double p = rand_0_1(); //����0~1֮��������
	if (p < prob[0]) return 0;
	if (p >= prob[POP_SIZE - 1]) return (POP_SIZE - 1);
	for (int i = 1; i < POP_SIZE; i++)
	{
		if ((p >= prob[i - 1]) && (p < prob[i])) return i;
	}
	return -1;
}
Matrix_Vector& Knapsack::crossOver(Matrix_Vector &pop)//Ⱥ�彻��
{
	for (int i = 0; i < POP_SIZE; i = i + 2)
	{
		for (int j = 0; j < item_num; j++)
		{
			if (rand_0_1() < PRO_CROSS)///////////////////////////���ڻ���С�ڣ�
			{
				int tmp = pop[i][j];
				pop[i][j] = pop[i + 1][j];
				pop[i + 1][j] = tmp;
			}
		}
	}
	return pop;
}
Matrix_Vector& Knapsack:: mutation(Matrix_Vector & pop)//����
{

	for (int i = 0; i<POP_SIZE; i++)   //������������ڱ����ʾͱ���
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
