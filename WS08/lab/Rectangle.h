///////////////////////////////////////////////////
// Workshop 8  : Rectangle.h
// Student Name: Rong-Yuan, Wen
// Student ID  : 114556228
// Email       : rwen1@myseneca.ca
// Section     : NGG
///////////////////////////////////////////////////
#ifndef SDDS_LBL_RECTANGLE_H
#define SDDS_LBL_RECTANGLE_H
#include "LblShape.h"
namespace sdds {
	class Rectangle: public LblShape
	{
		int m_width;
		int m_height;

	public:
		Rectangle(); // Default constructor
		Rectangle(const char* label, int width, int height); // Three argument constructor

		void getSpecs(std::istream& is) override; // Override getSpecs function
		void draw(std::ostream& os) const override; // Override draw function
	};
}

#endif // !SDDS_LBL_RECTANGLE_H