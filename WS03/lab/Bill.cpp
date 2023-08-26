///////////////////////////////////////////////////
// Workshop 3  : Bill.cpp
// Student Name: Rong-Yuan, Wen
// Student ID  : 114556228
// Email       : rwen1@myseneca.ca
// Section     : NGG
///////////////////////////////////////////////////

#include <iostream>
#include <iomanip>
#include "cstring.h"
#include "Bill.h"
using namespace std;
namespace sdds {

	double Bill::totalTax() const{
		double totalTax = 0.0;
		for (int i = 0; i < m_noOfItems; i++){
			totalTax += m_items[i].tax();
		}
		return totalTax;
	}

	double Bill::totalPrice() const{
		double totalPrice = 0.0;
		for (int i = 0; i < m_noOfItems; i++) {
			totalPrice += m_items[i].price();
		}
		return totalPrice;
	}

	void Bill::Title() const{
		cout << "+--------------------------------------+" << endl;

		if (isValid() && m_noOfItems == m_itemsAdded) {
			cout << "| " << left << setw(36) << m_title << " |" << endl;
		}
		else {
			cout << "| Invalid Bill                         |" << endl;
		}

		cout << "+----------------------+---------+-----+" << endl;
		cout << "| Item Name            | Price   + Tax |" << endl;
		cout << "+----------------------+---------+-----+" << endl;
	}

	void Bill::footer() const{
		cout << "+----------------------+---------+-----+" << endl;
		if (isValid() && m_noOfItems == m_itemsAdded) {
			cout << "|                Total Tax: " << right << setw(10) << fixed << setprecision(2) << totalTax() << " |" << endl;
			cout << "|              Total Price: " << right << setw(10) << fixed << setprecision(2) << totalPrice() << " |" << endl;
			cout << "|          Total After Tax: " << right << setw(10) << fixed << setprecision(2) << totalTax() + totalPrice() << " |" << endl;
		}
		else {
			cout << "| Invalid Bill                         |" << endl;
		}
		cout << "+--------------------------------------+" << endl;
	}

	void Bill::setEmpty(){
		m_title[0] = '\0';
		m_items = nullptr;
	}

	bool Bill::isValid() const{
		bool outcome = false;
		if (m_title[0] != '\0' && m_items != nullptr){
			for (int i = 0; i < m_itemsAdded; i++) {
				if (m_items[i].isValid()) {
					outcome = true;
				}
			}
		}
		return outcome;
	}

	void Bill::init(const char* title, int noOfItems){
		if (title == nullptr || noOfItems <= 0) {
			setEmpty();
		}
		else {
			m_itemsAdded = 0;
			m_noOfItems = noOfItems;
			strnCpy(m_title, title, 36);
			m_title[strLen(m_title)] = '\0';

			m_items = new Item[m_noOfItems];
			for (int i = 0; i < m_noOfItems; i++) {
				m_items[i].setEmpty();
			}
		}
	}

	bool Bill::add(const char* item_name, double price, bool taxed){
		bool outcome = false;
		if (m_itemsAdded < m_noOfItems) {
			m_items[m_itemsAdded].set(item_name, price, taxed);
			m_itemsAdded++;
			outcome = true;
		}
		return outcome;
	}

	void Bill::display() const{
		Title();
		for (int i = 0; i < m_noOfItems; i++) {
			m_items[i].display();
		}
		footer();
	}

	void Bill::deallocate(){
		delete[] m_items;
		m_items = nullptr;
	}
}