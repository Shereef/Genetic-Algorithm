#include <ctime>
#include<iostream>
#include<algorithm>
#include<vector>
#include"chromosome.h"
using namespace std;

vector<CChromosome> g_Chromosomes;

class CChromosome Create(int Genes)
{
	CChromosome x;
	x.	m_Fitness = 0;
	for(int i = 0; i < Genes; ++i)
		x.m_aGenes.push_back((rand()+rand()*rand()) % 2);
	x.CalcFitness();
	return x;
}

void Print()
{
	for(vector<CChromosome>::iterator it = g_Chromosomes.begin(); it != g_Chromosomes.end(); it++)
	{
		(*it).Print();
	}
}

void Sort()
{
	sort(g_Chromosomes.begin(), g_Chromosomes.end());
	reverse(g_Chromosomes.begin(), g_Chromosomes.end());
}

int Average()
{
	int Temp = 0;
	for(vector<CChromosome>::iterator it = g_Chromosomes.begin(); it != g_Chromosomes.end(); it++)
	{
		Temp += (*it).m_Fitness;
	}
	return Temp/g_Chromosomes.size();
}

int CrossOver()
{
	//Let's see who's below our threshold

	int Temp = 0;
	for(vector<CChromosome>::iterator it = g_Chromosomes.begin(); it != g_Chromosomes.end(); it++)
	{
		Temp += (*it).m_Fitness;
	}
	return Temp/g_Chromosomes.size();
}

void Clear()
{
	g_Chromosomes.clear();
}

int main()
{
	srand( (unsigned)time( NULL ) );
	while(true)
	{
		cout << "How many Chromosomes do you want ?\n";
		int Count = 10, Genes = 6;
		cin >> Count;
		cout << "How many genes do you want in each Chromosome ?\n";
		cin >> Genes;
		for(int i = 0; i < Count; ++i)
			g_Chromosomes.push_back(Create(Genes));
		cout << "Chromosomes:\n";
		Print();
		cout << "Ranks:\n";
		Sort();
		Print();
		cout << "Press Enter (Return) to Exit\n";
		cout << endl;
		cin.get();
		Clear();
	}
	return 0;
}
