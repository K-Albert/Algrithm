#ifndef __MATRIX_VECTOR_H
#define __MATRIX_VECTOR_H
#include <vector>
#include <iterator>
#include <stdint.h>
#include <iostream>
using namespace std;

enum
{
	ZERO = 0
};
class Matrix_Vector
{
private:
	vector<vector<double>> data;
	uint32_t colum=0;
	uint32_t row=0;
public:
	Matrix_Vector(uint32_t t_row, uint32_t t_colum);
	Matrix_Vector(uint32_t t_row, uint32_t t_colum, uint8_t kind);
	uint32_t getRow() const { return row; };
	uint32_t getColum()const { return colum; };
	double getData(uint32_t t_row, uint32_t t_colum) const { return data[t_row][t_colum]; };
	vector<double> & operator[] (uint32_t i){ return data[i]; };

};
ostream& operator << (ostream &os, Matrix_Vector &x);

#endif