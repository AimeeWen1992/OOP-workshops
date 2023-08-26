///////////////////////////////////////////////////
// Workshop 8  : LblShape.cpp
// Student Name: Rong-Yuan, Wen
// Student ID  : 114556228
// Email       : rwen1@myseneca.ca
// Section     : NGG
///////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include<cstring>
#include "LblShape.h"

namespace sdds {
	LblShape::LblShape(){}

	LblShape::LblShape(const char* label)
	{
		if (label) {
			m_label = new char[strlen(label) + 1];
			strncpy(m_label, label, strlen(label) + 1);
		}
	}

	LblShape::~LblShape()
	{
		delete[]m_label;
		m_label = nullptr;
	}

	void LblShape::getSpecs(std::istream& is)
	{
		char temp[100];
		is.getline(temp, 100, ',');
		if (m_label) {
			delete[] m_label;
		}
		m_label = new char[strlen(temp) + 1];
		strncpy(m_label, temp, strlen(temp) + 1);
	}

	char* LblShape::label() const
	{
		return m_label;
	}

}