///////////////////////////////////////////////////
// Workshop 3  : Food.h
// Student Name: Rong-Yuan, Wen
// Student ID  : 114556228
// Email       : rwen1@myseneca.ca
// Section     : NGG
///////////////////////////////////////////////////

#ifndef SDDS_FOOD_H
#define SDDS_FOOD_H

namespace sdds {
	class Food {
	private:
		char m_name[30 + 1];
		int m_calories;
		int m_timeOfConsumption;
	public:
		void setEmpty();
		void setAll(const char* name, int calories, int timeOfConsumption);
		void display()const;
		bool isValid()const;
		int setCalories()const;
		int setTimeOfConsumption()const;
	};
}
#endif // !SDDS_FOOD_H
