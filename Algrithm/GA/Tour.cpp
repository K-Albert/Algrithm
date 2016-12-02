#include "tour.h"

double Tour::cclResult(vector<double> &point, Matrix_Vector &dis)
{
	Matrix_Vector t_result(POINT_SIZE, POINT_SIZE, ZERO);

	double result = 0;
	for (int i = 0; i < POINT_SIZE; i++)
	{
		for (int j = 0; j < POINT_SIZE; j++)
		{
			if (point[j] - point[i] == 1 || point[j] - point[i] == (POINT_SIZE - 1))
				t_result[i][j] = 1;
		}
	}
	for (uint32_t i = 0; i < t_result.getRow(); i++)
	{
		for (uint32_t j = 0; j < t_result.getColum(); j++)
		{
			if (t_result[i][j])
				result += dis[i][j];
		}
	}

	return result;
}