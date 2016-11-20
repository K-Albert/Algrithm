#ifndef _MATRIX_H_
#define _MATRIX_H_
#include <iostream>
#include <stdint.h>
using namespace std;
enum
{
	ZERO = 0
};
class Matrix
{
 private:
	double** data;
	uint32_t row = 0;
	uint32_t colum = 0;
  public:
	  Matrix(uint32_t t_row,uint32_t t_colum);
	  Matrix(uint32_t t_row, uint32_t t_colum,uint8_t kind);
	  ~Matrix();
	  uint32_t getRow() const {  return row; };
	  uint32_t getColum()const { return colum; }; 
	  double getData(uint32_t t_row, uint32_t t_colum) const { return data[t_row][t_colum]; }; 
	  double* operator[] (uint32_t i){ return data[i]; };
	
};
ostream& operator << (ostream &os, Matrix &x);
#endif 
