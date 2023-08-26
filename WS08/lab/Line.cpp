///////////////////////////////////////////////////
// Workshop 8  : Line.cpp
// Student Name: Rong-Yuan, Wen
// Student ID  : 114556228
// Email       : rwen1@myseneca.ca
// Section     : NGG
///////////////////////////////////////////////////
#include <iostream>
#include "Line.h"
#include"Shape.h"
using namespace std;

namespace sdds {
	Line::Line()
	{
		m_length = 0;
	}

	Line::Line(const char* label, int length) : LblShape(label)
	{
		m_length = 0;
		if (length>0)
		{
			m_length = length;
		}
	}

	void Line::getSpecs(std::istream& is)
	{
		LblShape::getSpecs(is); // Call the base class getSpecs
		is >> m_length;
		is.ignore(100, '\n');
	}

	void Line::draw(std::ostream& os) const
	{
		if (m_length > 0 && label()) {
			os << label() << endl; // Go to the new line after printing the label
			for (int i = 0; i < m_length; ++i) {
				os << '='; 
			}
		}
	}

}