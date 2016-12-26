#ifndef __TOUR_H
#define __TOUR_H

#define POINT_SIZE 30
#define RESULT_SIZE 60
#define NEWPOP_SIZE 30


#include <algorithm>
#include "rand.h"
#include "matrix_vector.h"
#include "point.h"
class Tour
{
 public:
	double cclResult(uint32_t cnt);
	void cclDis(Point point[]);
	void cclnewPoP(uint32_t i,uint32_t individual);
	void resultSpace();
	void intersect();
	vector<double>& crossover(vector<double> &par1, vector<double>&par2);
	Tour() :Result(RESULT_SIZE, POINT_SIZE), Dis(POINT_SIZE, POINT_SIZE), newPoP(NEWPOP_SIZE, POINT_SIZE), crossPoP(RESULT_SIZE,POINT_SIZE)
	{
		result.resize(POINT_SIZE);
	};

 private:
	 Matrix_Vector Result;
	 Matrix_Vector newPoP;
	 Matrix_Vector Dis;
	 Matrix_Vector crossPoP;
	 vector<pair<uint32_t, float>> result;

};
bool cmp(const pair<uint32_t, float> &a, const pair<uint32_t, float> &b);



#endif 