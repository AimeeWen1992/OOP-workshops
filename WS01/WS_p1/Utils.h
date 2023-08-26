///////////////////////////////////////////////////
// Workshop 1  : Utils.h
// Student Name: Rong-Yuan, Wen
// Student ID  : 114556228
// Email       : rwen1@myseneca.ca
// Section     : NGG
///////////////////////////////////////////////////

#ifndef SDDS_ULILS_H 
#define SDDS_ULILS_H

namespace sdds {
	void flushkeys();

	bool ValidYesResponse(char ch);

	bool yes();

	void readCstr(char cstr[], int len);

	int readInt(int min, int max);
}
#endif