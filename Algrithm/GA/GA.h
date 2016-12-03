#ifndef _GA_H_
#define _GA_H_

#include <vector>
#include "rand.h"
#include <stdint.h>
#include <random>
#include<time.h>
#include "tour.h"
using namespace std;

class GA
{
private:
	vector<double> probi;
	vector<double> fitness;
	uint32_t size;
public:
	GA(uint32_t t_size)
	{
		size = t_size; probi.resize(size); fitness.resize(size);
	};
	int seletIndividual();
	void bulidWheel(Tour &tour);
	float result;
	int subscript;
	void generate();
};

class Result
{
	

};
#endif