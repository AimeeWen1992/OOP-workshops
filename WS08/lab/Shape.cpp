///////////////////////////////////////////////////
// Workshop 8  : Shape.cpp
// Student Name: Rong-Yuan, Wen
// Student ID  : 114556228
// Email       : rwen1@myseneca.ca
// Section     : NGG
///////////////////////////////////////////////////
#include "Shape.h"
namespace sdds {
	Shape::~Shape(){}

	std::ostream& operator<<(std::ostream& os, const Shape& shape)
	{
		shape.draw(os);
		return os;
	}

	std::istream& operator>>(std::istream& is, Shape& shape)
	{
		shape.getSpecs(is);
		return is;
	}

}