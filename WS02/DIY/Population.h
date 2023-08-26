///////////////////////////////////////////////////
// Workshop 2  : Population.h
// Student Name: Rong-Yuan, Wen
// Student ID  : 114556228
// Email       : rwen1@myseneca.ca
// Section     : NGG
///////////////////////////////////////////////////
#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_

struct Population{
	char poatalCode[3+1];
	int populationNo;
};

namespace sdds {
	void sort();
	bool load(const char* filename);
	bool load(struct Population& population);
	void display();
	void display(const Population& singlePopulation);
	void deallocateMemory();
	int totalPopulation();
}
#endif // SDDS_POPULATION_H_