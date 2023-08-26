#include<iostream>
#include<cstring>
#include "Rectangle.h"
///////////////////////////////////////////////////
// Workshop 8  : Rectangle.cpp
// Student Name: Rong-Yuan, Wen
// Student ID  : 114556228
// Email       : rwen1@myseneca.ca
// Section     : NGG
///////////////////////////////////////////////////
using namespace std;
namespace sdds {
	Rectangle::Rectangle(){
        m_width = 0;
        m_height = 0;
    }
	

	Rectangle::Rectangle(const char* label, int width, int height) : LblShape(label)
	{
        m_width = width;
        m_height = height;
        int labelWidth = strlen(LblShape::label() + 2);
		if (m_height < 3 || m_width < labelWidth) {
			// Set the Rectangle to an empty state
			m_width = 0;
			m_height = 0;
		}
	}

	void Rectangle::getSpecs(std::istream& is)
	{
		LblShape::getSpecs(is); // Call the base class getSpecs
        is >> m_width;
        is.ignore(1000, ',');
        is >> m_height;
        is.ignore(1000, '\n');
	}

	void Rectangle::draw(std::ostream& os) const
	{
        if (m_width && m_height) {
            os << '+';
            for (int i = 0; i < m_width - 2; i++) {
                os << '-';
            }
            os << '+' << endl;
            os << '|';
            os.setf(ios::left);
            os.width(m_width - 2);
            os.fill(' ');
            os << label();
            os.unsetf(ios::left);
            os << '|' << endl;
            for (int i = 0; i < m_height - 3; i++)
            {
                os << '|';
                for (int i = 0; i < m_width - 2; i++)
                {
                    os << ' ';
                }
                os << '|' << endl;;
            }
            os << '+';
            for (int i = 0; i < m_width - 2; i++)
            {
                os << '-';
            }
            os << '+';

        }
	}

}