///////////////////////////////////////////////////
// Workshop 1  : ShoppingList.h
// Student Name: Rong-Yuan, Wen
// Student ID  : 114556228
// Email       : rwen1@myseneca.ca
// Section     : NGG
///////////////////////////////////////////////////

#ifndef SDDS_SHOPPINGLIST_H 
#define SDDS_SHOPPINGLIST_H

namespace sdds {
	bool loadList();

	void displayList();

	void removeBoughtItems();

	void removeItem(int index);

	bool saveList();

	void clearList();

	void toggleBought();

	void addItemToList();

	void removeItemfromList();

	bool listIsEmpty();
}

#endif