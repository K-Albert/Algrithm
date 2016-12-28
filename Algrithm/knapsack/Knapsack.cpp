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
		if (isPop) i++;
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

vector<double> Knapsack::cclFitness(vector<double>&value, Matrix_Vector &pop, Matrix_Vector &weight,int size)//������Ⱥ��Ӧ��
{
	vector<double> fit(size*POP_SIZE);
	vector<double> tmpWeight;

	for (int i = 0; i < size*POP_SIZE; i++)
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
	//	sumFitness += fit[i]; //����Ӧ�ȣ�Ϊ���̶���׼��
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
Matrix_Vector Knapsack::crossOver(Matrix_Vector pop)//Ⱥ�彻��,���Ƚ���
{
	for (int i = 0; i < POP_SIZE-1; i = i + 1)
	{
		for (int j = 0; j < item_num; j++)
		{
			if (rand_0_1() > PRO_CROSS)///////////////////////////���ڻ���С�ڣ�
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
Matrix_Vector&  Knapsack::selectNewPop(Matrix_Vector& tmpPop, Matrix_Vector& newpop, Matrix_Vector& pop, Matrix_Vector& r_pop, vector<double>&value, Matrix_Vector &weight)
{
	vector<double> fit;
	vector<pair<uint32_t, double>> sort_fit( POP_SIZE);
	for (int i = 0; i < POP_SIZE; i++)
	{
		tmpPop[i] = pop[i];
	}
	for (int i = POP_SIZE; i < 2 * POP_SIZE; i++)
	{
		tmpPop[i] = newpop[i - POP_SIZE];
	}
	fit = cclFitness(value, tmpPop, weight, 2);

	for (int i = 0; i < 2 * POP_SIZE; i++)
	{
		sort_fit[i].first = i;
		sort_fit[i].second = fit[i];
	}
	sort(sort_fit.begin(), sort_fit.end(), cmp);//STL���Դ��㷨

	for (int i = 0; i < POP_SIZE; i++)
	{
		r_pop[i] = tmpPop[sort_fit[i].first];
	}
	return r_pop;

}

Matrix_Vector&  Knapsack::selectNewPop( Matrix_Vector& newpop, Matrix_Vector& pop, Matrix_Vector& r_pop, vector<double>&value, Matrix_Vector &weight)
{
	vector<double> fit_par;
	vector<double> fit_child;
	vector<pair<uint32_t, double>> sort_fit_par(POP_SIZE);
	vector<pair<uint32_t, double>> sort_fit_child(POP_SIZE);


	fit_par = cclFitness(value, pop, weight);
	fit_child = cclFitness(value, newpop, weight);
	for (int i = 0; i < POP_SIZE; i++)
	{
		sort_fit_par[i].first = i;
		sort_fit_par[i].second = fit_par[i];
	}
	for (int i = 0; i < POP_SIZE; i++)
	{
		sort_fit_child[i].first = i;
		sort_fit_child[i].second = fit_child[i];
	}

	sort(sort_fit_par.begin(), sort_fit_par.end(), cmp);//STL���Դ��㷨
	sort(sort_fit_child.begin(), sort_fit_child.end(), cmp);//STL���Դ��㷨

	for (int i = 0; i < POP_SIZE/2; i++)
	{
		r_pop[i] = pop[sort_fit_par[i].first];
	}
	for (int i = POP_SIZE / 2; i < POP_SIZE ; i++)
	{
		r_pop[i] = newpop[sort_fit_child[i-POP_SIZE/2].first];
	}
	return r_pop;

}
bool cmp(const pair<uint32_t, float> &a, const pair<uint32_t, float> &b){ return a.second > b.second; };