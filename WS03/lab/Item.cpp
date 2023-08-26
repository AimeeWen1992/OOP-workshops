///////////////////////////////////////////////////
// Workshop 3  : Item.cpp
// Student Name: Rong-Yuan, Wen
// Student ID  : 114556228
// Email       : rwen1@myseneca.ca
// Section     : NGG
///////////////////////////////////////////////////
#include <iostream>
#include <iomanip>
#include "cstring.h"
#include "Item.h"
using namespace std;
namespace sdds {

	void Item::setName(const char* name){
		int copyLength = (strLen(name) > 20) ? 20 : strLen(name);
		strnCpy(m_itemName, name, copyLength);
		m_itemName[copyLength] = '\0';
	}

	void Item::setEmpty(){
		m_itemName[0] = '\0';
	}

	void Item::set(const char* name, double price, bool taxed){
		if (name == nullptr || price < 0.0) {
			setEmpty();
		}
		else {
			setName(name);
			m_price = price;
			m_taxed = taxed;
		}
	}

	void Item::display() const{
		if (isValid()) { 
			cout << "| "  << left << setw(20) << setfill('.') << m_itemName
				 << " | " << fixed << setprecision(2) << right << setw(7)<< setfill(' ') << m_price
				 << " | " << (m_taxed ? "Yes" : "No ") << " |" << endl;
		}
		else {
			cout << "| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |" << endl;
		}
	}

	bool Item::isValid() const{	
		return (m_itemName[0] !='\0') ? true : false;
	}

	double Item::price() const{
		return m_price;
	}

	double Item::tax() const{
		const double tax = 0.13; 
		return m_taxed == true ? m_price * tax : 0.0;
	}
}
