///////////////////////////////////////////////////
// Workshop 3  : cstring.cpp
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

	int strCmp(const char* s1, const char* s2)
	{
		int valid = 0;

		if (strLen(s1) == strLen(s2))
		{
			for (int i = 0; i < strLen(s1); i++)
			{
				if (s1[i] != s2[i])
				{
					if (s1[i] < s2[i])
					{
						valid = -1;
					}
					else if (s1[i] > s2[i])
					{
						valid = 1;
					}
				}
			}
		}
		else
		{
			if (strLen(s1) > strLen(s2))
			{
				valid = 1;
			}
			else
			{
				valid = -1;
			}
		}
		return valid;
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
}