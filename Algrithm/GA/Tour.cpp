#include "tour.h"
#include "point.h"
double Tour::cclResult(uint32_t cnt)
{
	Matrix_Vector t_result(POINT_SIZE, POINT_SIZE, ZERO);

	double result = 0;
	for (int i = 0; i < POINT_SIZE; i++)
	{
		for (int j = 0; j < POINT_SIZE; j++)
		{
			if (Result[cnt][j] - Result[cnt][i] == 1 || Result[cnt][j] - Result[cnt][i] == (POINT_SIZE - 1))
				t_result[i][j] = 1;
		}
	}
	for (uint32_t i = 0; i < t_result.getRow(); i++)
	{
		for (uint32_t j = 0; j < t_result.getColum(); j++)
		{
			if (t_result[i][j])
				result += Dis[i][j];
		}
	}

	return result;
}
void Tour::cclDis(Point point[])///////////����ܲ���������
{
	for (int i = 0; i < POINT_SIZE; i++)
	{
		for (int j = i; j < POINT_SIZE; j++)
		{
			if (i == j)
				Dis[i][j] = 0;
			else
				Dis[i][j] = Dis[j][i] = sqrt(point[i].i_pow(point[i].x - point[j].x) + point[i].i_pow(point[i].y - point[j].y));
		}
	}
}
void Tour::resultSpace()
{
	for (int i = 0; i < RESULT_SIZE; i++)
	{
		for (int count = 0; count < POINT_SIZE; count++)
		{
			result[count].first = count + 1;
			result[count].second = rand_0_1();
		}
		//heap.heapSort(result, POINT_SIZE);//������ �������һ����
		sort(result.begin(), result.end(), cmp);//STL���Դ��㷨

		for (int j = 0; j < POINT_SIZE; j++)//�����ռ�
		{
			Result[i][j] = result[j].first;
		}
	}
	//cout << Result;
}

void Tour::cclnewPoP(uint32_t i,uint32_t individual)
{
	newPoP[i] = Result[individual];
	//for (int i = 0; i<POINT_SIZE; i++)
	//	cout << newPoP[individual][i]<<" ";
	//cout << endl;
}


void Tour::intersect()
{
	uint32_t randomID = 0;
	vector<double> parnt1(POINT_SIZE);
	vector<double> parnt2(POINT_SIZE);
	vector<double> child(POINT_SIZE);

	for (int i = 0; i < NEWPOP_SIZE; i++)
		crossPoP[i] = newPoP[i];
	for (int i = NEWPOP_SIZE; i < RESULT_SIZE; i++)
	{
		randomID = rand_0_1()*NEWPOP_SIZE;//�Ӹ�����ѡ�������
		parnt1 = newPoP[randomID];
		randomID = rand_0_1()*NEWPOP_SIZE;
		parnt2 = newPoP[randomID];
		crossPoP[i] = crossover(parnt1, parnt2);
	}
	cout << crossPoP;

}

vector<double>& Tour::crossover(vector<double> &par1, vector<double>&par2)
{
	vector<double> child(POINT_SIZE);
	struct gene
	{
		int pos;
		int flag;
	};

	vector<gene>tmp_gene(POINT_SIZE);

	int startPos = (int)(rand_0_1()*POINT_SIZE);//�Ƿ��п�������1  ����posʹ�������
	int endPos = (int)(rand_0_1()*POINT_SIZE);



	if (startPos > endPos)
	{
		int tmp = startPos;
		startPos = endPos;
		endPos = tmp;
	}
	for (int i = startPos; i < endPos; i++)
		child[i] = par1[i];

	for (int i = endPos; i < POINT_SIZE; i++)
	{
		tmp_gene[i].pos = par2[i];
		tmp_gene[i].flag = 1;
	}
	for (int i = 0; i < startPos; i++)
	{
		tmp_gene[i].pos = par2[i];
		tmp_gene[i].flag = 1;
	}

	for (int i = 0; i < POINT_SIZE; i++)
	{
		for (int j = startPos; j < endPos; j++)
		{
			if (child[j] == tmp_gene[i].pos)
				tmp_gene[i].flag = 0;
		}
	}


	for (int i = endPos; i < POINT_SIZE; i++)
	{
		if (tmp_gene[i].flag)
			child[i] = tmp_gene[i].pos;
	}
	for (int i = 0; i < startPos; i++)
	{
		if (tmp_gene[i].flag)
			child[i] = tmp_gene[i].pos;
	}
	return child;
}



bool cmp(const pair<uint32_t, float> &a, const pair<uint32_t, float> &b){ return a.second > b.second; };