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
void Tour::cclDis(Point point[])///////////如何能不复制数组
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
		//heap.heapSort(result, POINT_SIZE);//堆排序 随机产生一个解
		sort(result.begin(), result.end(), cmp);//STL库自带算法

		for (int j = 0; j < POINT_SIZE; j++)//放入解空间
		{
			Result[i][j] = result[j].first;
		}
	}
	//cout << Result;
}

void Tour::cclnewPoP(uint32_t individual)
{
	newPoP[individual] = Result[individual];
	//for (int i = 0; i<POINT_SIZE; i++)
	//	cout << newPoP[individual][i]<<" ";
	//cout << endl;
}
bool cmp(const pair<uint32_t, float> &a, const pair<uint32_t, float> &b){ return a.second > b.second; };