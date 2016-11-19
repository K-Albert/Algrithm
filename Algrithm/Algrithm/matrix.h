#ifndef _MATRIX_H_
#define _MATRIX_H_
#include <iostream>
#include <stdint.h>
class Matrix
{
 private:
	double** data;
	uint32_t row = 0;
	uint32_t colum = 0;
  public:
	  Matrix(uint32_t t_row,uint32_t t_colum);
	  ~Matrix();
	  double* operator[] (uint32_t i){ return data[i]; };
};
#endif 