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

int main()
{
	srand( (unsigned)time( NULL ) );
	cout << "How many Chromosomes do you want ?\n";
	int Count = 10, Genes = 6;
	//cin >> Count;
	cout << "How many genes do you want in each Chromosome ?\n";
	//cin >> Genes;
	for(int i = 0; i < Count; ++i)
		g_Chromosomes.push_back(Create(Genes));
	
	for(vector<CChromosome>::iterator it = g_Chromosomes.begin(); it != g_Chromosomes.end(); it++)
	{
		cout << it->m_Fitness;
		cout << "\n";
	}
	sort(g_Chromosomes.begin(), g_Chromosomes.end());
	reverse(g_Chromosomes.begin(), g_Chromosomes.end());
	cout << "==================\n";
	for(vector<CChromosome>::iterator it = g_Chromosomes.begin(); it != g_Chromosomes.end(); it++)
	{
		cout << it->m_Fitness;
		cout << "\n";
	}
	
	cout << "Press Enter (Return) to Exit\n";
	cout << endl;
	cin.get();
	return 0;
}
