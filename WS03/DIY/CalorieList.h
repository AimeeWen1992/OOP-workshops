///////////////////////////////////////////////////
// Workshop 3  : CalorieList.h
// Student Name: Rong-Yuan, Wen
// Student ID  : 114556228
// Email       : rwen1@myseneca.ca
// Section     : NGG
///////////////////////////////////////////////////

#ifndef SDDS_CALORIE_LIST_H
#define SDDS_CALORIE_LIST_H
#include "Food.h"

namespace sdds {
	class CalorieList{
	private:
		char m_title[30 + 1];
		Food* m_food;
		int m_noOfFoods;
		int m_foodsAdded;
		int totalCalories()const;
		void titleHead()const;
		void titleFoot()const;
		void setEmpty();
		bool isValidList()const;

	public:
		void init(int size);
		bool add(const char* item_name, int calories, int when);
		void display()const;
		void deallocate();
	};
}
#endif // !SDDS_CALORIE_LIST_H
