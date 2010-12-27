#include <ctime>
#include<iostream>
#include<algorithm>
#include<vector>
#include"chromosome.h"
using namespace std;

vector<CChromosome> g_Chromosomes;
int g_Count, g_Genes;

class CChromosome Create()
{
	CChromosome x;
	x.	m_Fitness = 0;
	for(int i = 0; i < g_Genes; ++i)
		x.m_aGenes.push_back((rand()+rand()*rand()) % 2);
	x.CalcFitness();
	return x;
}

void Print()
{
	for(vector<CChromosome>::iterator it = g_Chromosomes.begin(); it != g_Chromosomes.end(); it++)
	{
		it->Print();
	}
}

void Print(bool Numbering)
{
	int num = 0;
	for(vector<CChromosome>::iterator it = g_Chromosomes.begin(); it != g_Chromosomes.end(); it++)
	{
		cout << ++num;
		cout << ".\t";
		it->Print();
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
		Temp += it->m_Fitness;
	}
	return Temp/g_Chromosomes.size();
}

void CrossOver()
{
	//Let's see who's below our threshold
	int From = 0, Ave = Average(), Genes;
	bool Even = g_Genes % 2 == 0, Left;
	Genes = (Even)?g_Genes/2:(g_Genes/2)-1;

	for(vector<CChromosome>::iterator it = g_Chromosomes.begin(); it != g_Chromosomes.end(); it+)
	{
		if(it->m_Fitness < Ave)
			break;
		From++;
	}

	for(vector<CChromosome>::iterator it = g_Chromosomes.begin() + From; it != g_Chromosomes.end()-1; it++)
	{
		it->CrossOver((it+1)->GetMe(), Left = !Left, Genes);
	}
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
		cin >> g_Count;
		cout << "How many genes do you want in each Chromosome ?\n";
		cin >> g_Genes;
		for(int i = 0; i < g_Count; ++i)
			g_Chromosomes.push_back(Create());
		cout << "Chromosomes:\n";
		Print();
		cout << "Ranks:\n";
		Sort();
		Print(true);
		cout << "Press Enter (Return) to Reload\n";
		cout << endl;
		cin.get();
		Clear();
	}
	return 0;
}
