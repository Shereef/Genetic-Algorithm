#include<iostream>
#include"chromosome.h"
using namespace std;

int main()
{
	list<CChromosome*> Chromosomes;
	cout << "How many Chromosomes do you want ?\n";
	int Count, Genes;
	cin >> Count;
	cout << "How many genes do you want in each Chromosome ?\n";
	cin >> Genes;
	for(int i = 0; i < Count; ++i)
		Chromosomes.push_back(new CChromosome(Genes));
	cout << endl;
	return 0;
}