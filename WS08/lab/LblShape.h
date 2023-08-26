///////////////////////////////////////////////////
// Workshop 8  : LblShape.h
// Student Name: Rong-Yuan, Wen
// Student ID  : 114556228
// Email       : rwen1@myseneca.ca
// Section     : NGG
///////////////////////////////////////////////////
#ifndef SDDS_LBL_SHAPE_H
#define SDDS_LBL_SHAPE_H
#include "Shape.h"
namespace sdds {
	class LblShape: public Shape 
	{
		//hold the dynamically allocated label for the Shape.
		char* m_label{};

	public:
		LblShape();
		LblShape(const char* label);
		~LblShape();

		LblShape(const LblShape&) = delete;
		LblShape& operator=(const char&) = delete;

		void getSpecs(std::istream& is) override; // Override getSpecs function

	protected:
		char* label() const;
	};

}

#endif // !SDDS_LBL_SHAPE_H
