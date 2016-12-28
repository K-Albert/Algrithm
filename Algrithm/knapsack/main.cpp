#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <time.h>
#include "rand.h"
#include <stdint.h>
#include <vector>
#include <iterator>
#include <fstream>
#include "matrix_vector.h"
#include "Knapsack.h"
using namespace std;

#define N 50 //物品个数
#define M 5 //背包个数

//vector<double> capicity1 = { 80, 96, 20, 36, 44, 48, 10, 18, 22, 24 };//背包容量
//vector<double> value1    = { 100 ,600 ,1200, 2400, 500, 2000 };          //物品价值
//vector<double> value1 = { 600.1, 310.5, 1800, 3850, 18.6, 198.7, 882, 4200, 402.5, 327 };
//vector<double> capicity1 = { 450 ,540, 200, 360, 440, 480, 200, 360, 440, 480 };
//vector<double> value1 = { 100 ,220, 90, 400, 300, 400, 205, 120, 160, 580, 400, 140, 100, 1300, 650 };
//vector<double> capicity1 = { 550, 700, 130, 240, 280, 310, 110, 205, 260, 275 };
vector<double> value1 = { 560, 1125, 300, 620, 2100, 431 ,68 ,328, 47, 122, 322 ,196, 41, 25, 425, 4260,416, 115, 82 ,22 ,631, 132, 420 ,86 ,42 ,103 ,215 ,81, 91, 26 ,49 ,420,316, 72, 71 ,49 ,108, 116, 90, 738, 1811, 430, 3060, 215, 58, 296, 620, 418,47, 81};
vector<double> capicity1 = { 800, 650, 550, 550 ,650 };
void main()
{
	int i = 1;
	Knapsack knapsack(M,N);
	Matrix_Vector Weight(M,N);
	Matrix_Vector Population(POP_SIZE,N);
	Matrix_Vector childPopulation(POP_SIZE, N);
	Matrix_Vector newPopulation(POP_SIZE, N);
	Matrix_Vector tmpPopulation((2 * POP_SIZE), N);
	vector<double> Fitness(POP_SIZE);
	vector<double> Probility(POP_SIZE);
	vector<double> Best(N);
	double bestFitness=0;
	srand((unsigned)time(0));

	const char filename[] = "4.txt"; //保存数据的文件
	ofstream o_file;   /* 输出流：将数据从内存输出   其中ofstream是将数据输出到文件，因此对于文件来说是“写”*/
	ifstream i_file;   /*将数据输入到内存，其中ifstream是说输入的数据在文件中，因此对于文件来说是“读”*/

	i_file.open(filename);
	if (i_file.is_open())     //读取出数据 
	{
		int column = 0,row = 0; 
		while (column < M )
		{
			while ((i++) % (N+1))
			{
				i_file >> Weight[column][row++];
			}
			row = 0;
			column++;
		}
		i_file.close();
	}

	int individual = 0;
	int bestIndividual = 0;
	knapsack.setCapcity(capicity1);          //设置M个背包容量
	knapsack.initPop(Weight, Population);     //初始化种群
	

	for (int generation = 0; generation < GENERATION_NUM; generation++)
	{
		Fitness = knapsack.cclFitness(value1, Population,Weight);  //计算适应度

		bestIndividual = knapsack.sortBest(Fitness, bestFitness);//记录最优个体
		if (bestIndividual != -1)
		{
			bestFitness = Fitness[bestIndividual];
			Best = Population[bestIndividual];
		}

		Probility = knapsack.buildWheel(Fitness);  //初始化轮盘赌
		for (int i = 0; i < POP_SIZE; i++)        //选择产生交配池
		{
			individual = knapsack.seletIndividual(Probility);
			if (individual != -1)
				newPopulation[i] = Population[individual];
			else
				i--;
		}
		childPopulation = knapsack.crossOver(newPopulation); //交叉
		childPopulation = knapsack.mutation(childPopulation);  //变异
//		Population = childPopulation;

//		Population = knapsack.selectNewPop(tmpPopulation, childPopulation, newPopulation, Population, value1, Weight);
	//	if (generation < GENERATION_NUM/3*2)
			Population = childPopulation;
	//	else                     
	//	    Population = knapsack.selectNewPop(childPopulation, newPopulation, Population, value1, Weight);
		
		
		cout << bestFitness<<endl;
	}

	



	



	system("pause");

}