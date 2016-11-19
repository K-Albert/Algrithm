#include "matrix.h"
Matrix::Matrix(uint32_t t_row, uint32_t t_colum)
{
	row = t_row;
	colum = t_colum;
	data = new double*[t_row];
	for (int i = 0; i < t_row; i++)
	{
		data[i] = new double[t_colum];
	}
}
Matrix::~Matrix()
{
	for (uint32_t i = 0; i < row; i++)
	{
		delete[] data[i];
	}
	delete[] data;
}