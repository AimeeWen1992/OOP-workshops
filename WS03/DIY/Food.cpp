///////////////////////////////////////////////////
// Workshop 3  : Food.cpp
// Student Name: Rong-Yuan, Wen
// Student ID  : 114556228
// Email       : rwen1@myseneca.ca
// Section     : NGG
///////////////////////////////////////////////////

#include <iostream>
#include <iomanip>
#include "Food.h"
#include "cstring.h"

using namespace std;
namespace sdds {
	void Food::setEmpty(){
		m_name[0] = '\0';
		m_calories = 0;
	}

	void Food::setAll(const char* name, int calories, int timeOfConsumption){
		if (name == nullptr || calories < 0)
		{
			setEmpty();
		}
		else{
			int copyLength = (strLen(name) > 30) ? 30 : strLen(name);
			strnCpy(m_name, name, copyLength);
			m_calories = calories;
			m_timeOfConsumption = timeOfConsumption;
		}
	}

	void Food::display() const{
		if (isValid())
		{
			cout << "| ";
			cout << left << setw(30) << setfill('.') << m_name << setfill(' ')
				 << " | " << right << setw(4) << m_calories;
			cout << " | " << left << setw(10);
			switch (m_timeOfConsumption)
			{
			case 1:
				cout << "Breakfast";
				break;
			case 2:
				cout << "Lunch";
				break;
			case 3:
				cout << "Dinner";
				break;
			case 4:
				cout << "Snack";
				break;
			}
			cout << " |" << endl;
		}
		else
		{
			cout << "| xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx | xxxx | xxxxxxxxxx |" << endl;
		}
	}

	bool Food::isValid() const
	{
		return (m_name[0] != '\0' && m_calories > 0 && m_timeOfConsumption > 0 && m_timeOfConsumption < 5) ? 
				true : false;
	}

	int Food::setCalories() const
	{
		return (m_calories > 0 && m_calories < 3001) ? m_calories : 0;
	}

}
