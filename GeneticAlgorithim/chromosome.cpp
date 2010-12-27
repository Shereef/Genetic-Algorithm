#include"chromosome.h"
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