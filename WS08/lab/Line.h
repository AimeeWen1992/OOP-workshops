///////////////////////////////////////////////////
// Workshop 8  : Line.h
// Student Name: Rong-Yuan, Wen
// Student ID  : 114556228
// Email       : rwen1@myseneca.ca
// Section     : NGG
///////////////////////////////////////////////////
#ifndef SDDS_LBL_LINE_H
#define SDDS_LBL_LINE_H
#include "LblShape.h"
namespace sdds {
	class Line: public LblShape
	{
		int m_length;
	public:
		Line();
		Line(const char* label, int length);
		void getSpecs(std::istream& is) override; // Override getSpecs function
		void draw(std::ostream& os) const override; // Override draw function
	};

}

#endif // !SDDS_LBL_LINE_H