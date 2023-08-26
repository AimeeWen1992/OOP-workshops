///////////////////////////////////////////////////
// Workshop 4  : LabelMaker.cpp
// Student Name: Rong-Yuan, Wen
// Student ID  : 114556228
// Email       : rwen1@myseneca.ca
// Section     : NGG
///////////////////////////////////////////////////
#include <iostream>
#include "LabelMaker.h"
using namespace std;
namespace sdds {
	LabelMaker::LabelMaker()
	{
		labels = nullptr;
		m_noOfLabels = 0;
	}
	LabelMaker::~LabelMaker()
	{
		delete[] labels;
	}
	LabelMaker::LabelMaker(int noOfLabels)
	{
		m_noOfLabels = noOfLabels;
		labels = new Label[noOfLabels];
	}
	void LabelMaker::readLabels()
	{
		cout << "Enter " << m_noOfLabels << " labels:" << endl;
		for (int i = 0; i < m_noOfLabels; i++) {
			cout << "Enter label number " << i + 1 << endl << "> ";
			labels[i].readLabel();
		}
	}
	void LabelMaker::printLabels()
	{
		for (int i = 0; i < m_noOfLabels; i++)
		{
			labels[i].printLabel();
		}
	}
}
