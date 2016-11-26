#include "tubu_search.h"
#include "matrix.h"
#include <iostream>
#include <stdlib.h>

using namespace std;
#define TUBU_SEIZE 50
uint32_t row2swap = 0;
uint32_t colum2swap = 0;
double cclResult(char* vector, Matrix &dis)
{
	Matrix t_result(SIZE, SIZE, ZERO);

	double result = 0;
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (vector[j] - vector[i] == 1 || vector[j] - vector[i] == (SIZE-1))
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
double opt_2(Matrix &delta,Matrix & dis,Matrix &tubu,char* vector,double result)
{
	char* temp_result_vector;
	temp_result_vector = new char[SIZE];
	double result_new = 0;


	for (uint32_t i = 0; i < delta.getRow(); i++)
	{
		for (uint32_t j = 0; j <delta.getColum(); j++)
		{
			if (i != j && !tubu[i][j])
			{
				memcpy(temp_result_vector, vector, SIZE);//watch out
				swap(temp_result_vector[i], temp_result_vector[j]);
				result_new = cclResult(temp_result_vector, dis);
				//cout << result_new << endl;
				delta[i][j] = result_new - result;
				//cout << delta;
			}
		}
	}


	double base_value=0;
	base_value = delta.getData(0,0);
	//找到delta中最大/小的
	for (uint32_t i = 0; i < delta.getRow(); i++)
	{
		for (uint32_t j = i; j < delta.getColum(); j++)
		{
			if (delta.getData(i, j) <= base_value )
			{
				base_value = delta.getData(i,j);
				row2swap = i;
				colum2swap = j;
			}
		}
	}

	memcpy(temp_result_vector, vector, SIZE);  //watch out
	swap(temp_result_vector[row2swap], temp_result_vector[colum2swap]);
	result_new = cclResult(temp_result_vector, dis);

	return result_new;
}

double breakTubu(Matrix &delta, Matrix & dis, Matrix &tubu, char* vector, double result)
{
	char* temp_result_vector;
	temp_result_vector = new char[SIZE];
	double result_new = 0;


	for (uint32_t i = 0; i < delta.getRow(); i++)
	{
		for (uint32_t j = 0; j <delta.getColum(); j++)
		{
			if (i != j )
			{
				memcpy(temp_result_vector, vector, SIZE);//watch out
				swap(temp_result_vector[i], temp_result_vector[j]);
				result_new = cclResult(temp_result_vector, dis);
				//cout << result_new << endl;
				delta[i][j] = result_new - result;
				//cout << delta;
			}
		}
	}


	double base_value = 0;
	base_value = delta.getData(0, 0);
	//找到delta中最大/小的
	for (uint32_t i = 0; i < delta.getRow(); i++)
	{
		for (uint32_t j = i; j < delta.getColum(); j++)
		{
			if (delta.getData(i, j) <= base_value)
			{
				base_value = delta.getData(i, j);
				row2swap = i;
				colum2swap = j;
			}
		}
	}

	memcpy(temp_result_vector, vector, SIZE);  //watch out
	swap(temp_result_vector[row2swap], temp_result_vector[colum2swap]);
	result_new = cclResult(temp_result_vector, dis);

	return result_new;
}

void updataTubu(Matrix &tubu)
{
	tubu[getLocationRow()][getLocationColum()] = TUBU_SEIZE;

	for (uint32_t i = 0; i < tubu.getRow(); i++)
	{
		for (uint32_t j = i + 1; j < tubu.getColum(); j++)
		{
			if (tubu[i][j])
				tubu[i][j]--;
		}
	}
}

bool abnormalStop(Matrix &Tubu)
{
	uint32_t cnt = 0;
	for (uint32_t i = 0; i < Tubu.getRow(); i++)
	{
		for (uint32_t j = i+1; j < Tubu.getColum(); j++)
		{
			if (Tubu.getData(i, j))
				cnt++;
		}
	}
	if (cnt >= C(SIZE, 2))
		return false;
	else
		return true;
}

uint32_t A(uint32_t m,uint32_t n)
{
	uint32_t result=1, cnt = 0;
	cnt =  n ;
	for (uint32_t i = 0; i < cnt; i++)
	{
		result*=(m - i);
	}
	return result;
}
uint32_t C(uint32_t m, uint32_t n)
{
	uint32_t result=0;

	result = A(m, n) / A(n, n);
	return result;
}

void setLocationRow(uint32_t i)
{
	row2swap = i;
}

uint32_t getLocationRow()
{
	return row2swap;
}

void setLocationColum(uint32_t j)
{
	colum2swap = j;
}

uint32_t getLocationColum()
{
	return colum2swap;
}
int i_pow(int x)
{
	return (x*x);
}