///////////////////////////////////////////////////
// Workshop 2  : Population.cpp
// Student Name: Rong-Yuan, Wen
// Student ID  : 114556228
// Email       : rwen1@myseneca.ca
// Section     : NGG
///////////////////////////////////////////////////
#include <iostream>
#include "Population.h"
#include "File.h"

using namespace std;

namespace sdds {

	int noOfPopulations;
	Population* populations;

	void sort()
	{
		int i, j;
		Population temp;
		for (i = noOfPopulations - 1; i > 0; i--)
		{
			for (j = 0; j < i; j++)
			{
				if (populations[j].populationNo > populations[j + 1].populationNo)
				{
					temp = populations[j];
					populations[j] = populations[j + 1];
					populations[j + 1] = temp;
				}
			}
		}
	}

	bool load(const char* filename)
	{
		bool ok = false;
		int count = 0;
		if (openFile(filename))
		{
			noOfPopulations = noOfRecords();
			populations = new Population[noOfPopulations];

			for (int i = 0; i < noOfPopulations; i++)
			{
				if (read(populations[i].poatalCode) && read(populations[i].populationNo))
				{
					count++;
				}
			}

			if (count != noOfPopulations)
			{
				ok = false;
				cout << "Error: incorrect number of records read; the data is possibly corrupted" << endl;
			}
			else
			{
				ok = true;
			}	

			closeFile();
		}
		else
		{
			cout << "Could not open data file: " << filename << endl;
		}

		return ok;
	}

	void display()
	{
		sort();
		cout << "Postal Code: population" << endl;
		cout << "-------------------------" << endl;
		for (int i = 0; i < noOfPopulations; i++)
		{
			cout << i + 1 << "- ";
			display(populations[i]);
		}
		cout << "-------------------------" << endl;
		cout << "Population of Canada: " << totalPopulation() << endl;
	}

	void display(const Population& singlePopulation){
		cout << singlePopulation.poatalCode << ":  " << singlePopulation.populationNo << endl;
	}

	void deallocateMemory(){
		delete[] populations;
		populations = nullptr;
	}

	int totalPopulation(){
		int total = 0;
		for (int i = 0; i < noOfPopulations; i++)
		{
			total += populations[i].populationNo;
		}
		return total;
	}
}