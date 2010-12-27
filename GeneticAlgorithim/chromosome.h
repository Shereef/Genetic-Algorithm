#include<list>
using namespace std;

class CChromosome
{

private:
	int m_Fitness;
	
public:
	CChromosome();
	list<bool> m_aGenes;
	int GetFitness();
	void CalcFitness();
};