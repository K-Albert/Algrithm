#include "matrix.h"
Matrix::Matrix(uint32_t t_row, uint32_t t_colum)
{
	row = t_row;
	colum = t_colum;
	data = new double*[t_row];
	for (uint32_t i = 0; i < t_row; i++)
	{
		data[i] = new double[t_colum];
	}
}
Matrix::Matrix(uint32_t t_row, uint32_t t_colum, uint8_t kind)
{
	row = t_row;
	colum = t_colum;
	data = new double*[t_row];
	for (uint32_t i = 0; i < t_row; i++)
	{
		data[i] = new double[t_colum];
	}
	switch (kind)
	{
	case ZERO:
		for (uint32_t i = 0; i < row; i++)
		{
			for (uint32_t j = i; j < colum; j++)
			{
				data[i][j] = data[j][i] = 0;
			}
		}
		break;
	default:
		break;
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


ostream& operator<<(ostream& os,Matrix &x)
{
	for (uint32_t i = 0; i < x.getRow(); i++)
	{
		for (uint32_t j = 0; j < x.getColum(); j++)
		{
			os << x.getData(i, j);
			os << " ";
			if (j == x.getColum() - 1) os << endl;
		}
	}
	return os;

}