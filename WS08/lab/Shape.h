///////////////////////////////////////////////////
// Workshop 8  : Shape.h
// Student Name: Rong-Yuan, Wen
// Student ID  : 114556228
// Email       : rwen1@myseneca.ca
// Section     : NGG
///////////////////////////////////////////////////
#ifndef SDDS_SHAPE_H
#define SDDS_SHAPE_H
#include <iostream>

namespace sdds {
	class Shape
	{
	public:
		//Pure virtual function: virtual Type identifier(parameters) = 0
		virtual void draw(std::ostream& os)const = 0;
		virtual void getSpecs(std::istream& is) = 0;
		virtual ~Shape();
	};
	std::ostream& operator<<(std::ostream& os, const Shape& shape);
	std::istream& operator>>(std::istream& is, Shape& shape);
}
#endif // !SDDS_SHAPE_H
