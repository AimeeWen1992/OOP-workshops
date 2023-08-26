///////////////////////////////////////////////////
// Workshop 6  : cstring.cpp
// Student Name: Rong-Yuan, Wen
// Student ID  : 114556228
// Email       : rwen1@myseneca.ca
// Section     : NGG
///////////////////////////////////////////////////
#include "cstring.h"
namespace sdds {
	void strCpy(char* des, const char* src)
	{
		int i;
		for (i = 0; i < strLen(src); i++)
		{
			des[i] = src[i];
		}
		des[i] = '\0';
	}
	int strLen(const char* s)
	{
		int count = 0;

		for (int i = 0; s[i] != '\0'; i++)
		{
			count += 1;
		}
		return count;
	}
	void strCat(char* des, const char* src)
	{
		char* temp = nullptr;

		if (*des != '\0')
		{
			while (*des != '\0')
			{
				des++;
			}
		}
		temp = des;
		strCpy(temp, src);
		des = temp;
	}
}