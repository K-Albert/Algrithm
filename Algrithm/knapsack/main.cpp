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

#define Q3 0


#ifdef Q0
#define N 6 //物品个数
#define M 10 //背包个数
const char filename[] = "1.txt";
vector<double> capicity1 = { 80, 96, 20, 36, 44, 48, 10, 18, 22, 24 };//背包容量
vector<double> value1    = { 100 ,600 ,1200, 2400, 500, 2000 };          //物品价值
#endif

#ifdef Q1
#define N 10 //物品个数
#define M 10 //背包个数
const char filename[] = "2.txt";
vector<double> value1 = { 600.1, 310.5, 1800, 3850, 18.6, 198.7, 882, 4200, 402.5, 327 };
vector<double> capicity1 = { 450 ,540, 200, 360, 440, 480, 200, 360, 440, 480 };
#endif

#ifdef Q2
#define N 15 //物品个数
#define M 10 //背包个数
const char filename[] = "3.txt";
vector<double> value1 = { 100 ,220, 90, 400, 300, 400, 205, 120, 160, 580, 400, 140, 100, 1300, 650 };
vector<double> capicity1 = { 550, 700, 130, 240, 280, 310, 110, 205, 260, 275 };
#endif

#ifdef Q3
#define N 50 //物品个数
#define M 5 //背包个数
const char filename[] = "4.txt";
vector<double> value1 = { 560, 1125, 300, 620, 2100, 431, 68, 328, 47, 122, 322, 196, 41, 25, 425, 4260, 416, 115, 82, 22, 631, 132, 420, 86, 42, 103, 215, 81, 91, 26, 49, 420, 316, 72, 71, 49, 108, 116, 90, 738, 1811, 430, 3060, 215, 58, 296, 620, 418, 47, 81 };
vector<double> capicity1 = { 800, 650, 550, 550, 650 };
#endif





void main()
{
	int i = 1;
	Knapsack knapsack(M,N);
	Matrix_Vector Weight(M,N);
	Matrix_Vector Population(POP_SIZE,N);
	Matrix_Vector childPopulation(POP_SIZE, N);
	Matrix_Vector competition( 4 , N);

	vector<double> Fitness(POP_SIZE);

	vector<double> Probility(POP_SIZE);
	vector<double> Best(N);
	vector<pair<uint32_t, double>> sort_fit(POP_SIZE);

	double bestFitness=0;

	srand((unsigned)time(0));

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
	int noup = 0;
	knapsack.setMutate(0.955);
	knapsack.setSim(0.6);
	knapsack.setCapcity(capicity1);          //设置M个背包容量
	knapsack.initPop(Weight, Population);     //初始化种群
	
	
	for (int generation = 0; generation < GENERATION_NUM; generation++)
	{

		Fitness = knapsack.cclFitness(value1, Population, Weight);  //计算适应度

		bestIndividual = knapsack.sortBest(Fitness, bestFitness);//记录最优个体
		if (bestIndividual != -1)
		{			
			bestFitness = Fitness[bestIndividual];
			Best = Population[bestIndividual];
			noup = 0;
		}
		else
		{
			//noup++;
			//if (noup == 200)
			//{
			//	knapsack.setMutate(0.9);
			//}
			//if (noup> 200)
			//cout << "gg"<<endl;
			//	for (int j = POP_SIZE * PROPOTIY; j < POP_SIZE; j++)
			//	{
			//		for (int k = 0; k < N; k++)
			//		{
			//			childPopulation[j][k] = rand() % 2;
			//		}
			//	}
			//}
			//if (noup > 250 && noup <350)
			//{
			//	cout << "很久没有进步" << endl;
			//	//knapsack.setSim(0.8);
			//	knapsack.setMutate(0.95);
			//}
			//else if (noup >= 350 && noup <450)
			//{
			//	knapsack.setMutate(0.9);
			//	cout << "老久没有进步" << endl;
			//}
			//else if (noup >= 450)
			//{
			//	knapsack.setMutate(0.8);
			//	cout << "gg" << endl;
			//}
		}

		//if (generation > 200)

			childPopulation = knapsack.bornChild3(childPopulation, Population, Fitness, value1, Weight, competition);
		//else
		//     childPopulation = knapsack.bornChild2(childPopulation, Population, Fitness, value1, Weight, competition);


			Population = childPopulation;

			cout << bestFitness << " " << generation << endl;
		if (bestFitness == 16537)
		{
			cout << generation <<endl ;
			break;
		}
	}

	



	

	//for (int j = POP_SIZE * (PROPOTIY ); j < POP_SIZE ; j++)
	//{
	//	childPopulation[j] = Population[sort_fit[j - POP_SIZE*(PROPOTIY)].first];
	//}
	//for (int j = POP_SIZE * PROPOTIY; j < POP_SIZE; j++)
	//{
	//	for (int k = 0; k < N; k++)
	//	{
	//		childPopulation[j][k] = rand() % 2;
	//	}
	//}


	/*


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
	*/



	system("pause");

}