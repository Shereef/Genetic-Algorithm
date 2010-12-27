#include"chromosome.h"
#include<iostream>

/*
*	CChromosome::CChromosome()
*	{
*		m_Fitness = -1;
*	}
*/

CChromosome::CChromosome(int Genes)
{
	m_Fitness = -1;
	for(int i = 0; i < Genes; ++i)
		m_aGenes.push_back(rand() % 2);
}

int CChromosome::GetFitness()
{
	if(m_Fitness == -1 )
		CalcFitness();
	return m_Fitness;
}

void CChromosome::CalcFitness()
{
	m_Fitness = 0;
	for (list<bool>::iterator it=m_aGenes.begin(); it!=m_aGenes.end(); ++it)
		m_Fitness += *it;
}
