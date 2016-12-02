#ifndef _TUBU_SEARCH_H_
#define _TUBU_SEARCH_H_

#include <stdint.h>
#include "matrix.h"
#define SIZE 30
uint32_t A(uint32_t m, uint32_t n);
uint32_t C(uint32_t m, uint32_t n);
double cclResult(char* vector, Matrix &dis);
double opt_2(Matrix &delta, Matrix & dis, Matrix &tubu, char* vector, double result);
double breakTubu(Matrix &delta, Matrix & dis, Matrix &tubu, char* vector, double result);
void setLocationRow(uint32_t i);
uint32_t getLocationRow();
void setLocationColum(uint32_t j);
uint32_t getLocationColum();
void updataTubu(Matrix &tubu);
bool abnormalStop(Matrix &Tubu);




#endif