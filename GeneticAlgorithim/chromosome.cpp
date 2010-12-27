#include"chromosome.h"
#include <stdio.h>
#include<iostream>


CChromosome::CChromosome()
{
	m_Fitness = -1;
}

void CChromosome::CalcFitness()
{
	m_Fitness = 0;
	for (list<bool>::iterator it=m_aGenes.begin(); it!=m_aGenes.end(); ++it)
		m_Fitness += *it;
}

void CChromosome::Print()
{
	m_aGenes.sort();
	printf("Chromosome: ");
	for (list<bool>::iterator it=m_aGenes.begin(); it!=m_aGenes.end(); ++it)
		printf("%d", *it);
	printf("\tFitness: %d\n",m_Fitness);
}

void CChromosome::CrossOver(CChromosome* pChrm, bool Left, int Size)
{

}
