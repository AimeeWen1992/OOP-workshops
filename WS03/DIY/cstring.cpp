///////////////////////////////////////////////////
// Workshop 3  : cstring.cpp
// Student Name: Rong-Yuan, Wen
// Student ID  : 114556228
// Email       : rwen1@myseneca.ca
// Section     : NGG
///////////////////////////////////////////////////

#include "cstring.h"

namespace sdds {

	void strnCpy(char* des, const char* src, int len) {
		int i;
		if (strLen(src) < len) {
			for (i = 0; src[i] != '\0'; i++)
			{
				des[i] = src[i];
			}
			des[i] = '\0';
		}
		else {
			for (i = 0; i < len; i++) {
				des[i] = src[i];
			}
			des[i] = '\0';
		}
	}

	int strLen(const char* s) {
		int count = 0;
		for (int i = 0; s[i] != '\0'; i++) {
			count += 1;
		}
		return count;
	}
}