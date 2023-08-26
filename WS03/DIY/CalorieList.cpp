///////////////////////////////////////////////////
// Workshop 3  : CalorieList.cpp
// Student Name: Rong-Yuan, Wen
// Student ID  : 114556228
// Email       : rwen1@myseneca.ca
// Section     : NGG
///////////////////////////////////////////////////

#include <iostream>
#include <iomanip>
#include "CalorieList.h"
#include "Food.h"
using namespace std;
namespace sdds {
	int CalorieList::totalCalories() const{
		int total = 0;
		for (int i = 0; i < m_noOfFoods; i++){
			total += m_food[i].setCalories();
		}
		return total;
	}

	void CalorieList::titleHead() const{
		cout << "+----------------------------------------------------+" << endl;
		if (isValidList()){
			cout << "|  Daily Calorie Consumption                         |" << endl;
		}
		else{
			cout << "| Invalid Calorie Consumption list                   |" << endl;
		}
		cout << "+--------------------------------+------+------------+" << endl;
		cout << "| Food name                      | Cals | When       |" << endl;
		cout << "+--------------------------------+------+------------+" << endl;
	}

	void CalorieList::titleFoot() const{
		cout << "+--------------------------------+------+------------+" << endl;
		if (isValidList() && m_noOfFoods == m_foodsAdded){
			cout << "|    Total Calories for today:" << right << setw(9) << totalCalories()
				<< " |            |" << endl;
		}
		else{
			cout << "|    Invalid Calorie Consumption list                |" << endl;
		}
		cout << "+----------------------------------------------------+" << endl;
	}

	void CalorieList::setEmpty(){
		m_title[0] = '\0';
		m_food = nullptr;
	}

	bool CalorieList::isValidList() const{
		bool outcome = false;
		int count = 0;
		if (m_food != nullptr){
			for (int i = 0; i < m_foodsAdded; i++){
				if (m_food[i].isValid()){
					count++;
				}
			}
			if (count == m_noOfFoods){
				outcome = true;
			}
		}
		return outcome;
	}

	void CalorieList::init(int size){
		if (size < 1){
			setEmpty();
		}
		else{
			m_noOfFoods = size;
			m_foodsAdded = 0;
			m_food = new Food[m_noOfFoods];
			for (int i = 0; i < m_noOfFoods; i++){
				m_food[i].setEmpty();
			}
		}
	}

	bool CalorieList::add(const char* item_name, int calories, int when){
		bool outcome = false;
		if (m_foodsAdded < m_noOfFoods){
			m_food[m_foodsAdded].setAll(item_name, calories, when);
			m_foodsAdded++;
			outcome = true;
		}
		return outcome;
	}

	void CalorieList::display() const{
		titleHead();
		for (int i = 0; i < m_noOfFoods; i++){
			m_food[i].display();
		}
		titleFoot();
	}

	void CalorieList::deallocate(){
		delete[] m_food;
		m_food = nullptr;
	}
}