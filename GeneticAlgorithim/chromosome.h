#include<list>
using namespace std;

class CChromosome
{
public:
	CChromosome();
	int m_Fitness;
	list<bool> m_aGenes;
	void CalcFitness();
	bool operator<(const CChromosome &rhs) const { return m_Fitness < rhs.m_Fitness; }
};
