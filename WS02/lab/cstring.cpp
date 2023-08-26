///////////////////////////////////////////////////
// Workshop 2  : cstring.cpp
// Student Name: Rong-Yuan, Wen
// Student ID  : 114556228
// Email       : rwen1@myseneca.ca
// Section     : NGG
///////////////////////////////////////////////////

#include "cstring.h"

using namespace std;

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

	void strnCpy(char* des, const char* src, int len)
	{
		int i;

		if (strLen(src) < len)
		{
			for (i = 0; src[i] != '\0'; i++)
			{
				des[i] = src[i];
			}
			des[i] = '\0';
		}
		else
		{
			for (i = 0; i < len; i++)
			{
				des[i] = src[i];
			}
		}
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

	int strnCmp(const char* s1, const char* s2, int len)
	{
		int valid = 0;
		if (len > 0 && len <= strLen(s1) && len <= strLen(s2))
		{
			for (int i = 0; i < len; i++)
			{
				valid += s1[i] - s2[i];
			}	
		}
		else
		{
			valid = strCmp(s1, s2);
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

	const char* strStr(const char* str1, const char* str2)
	{
		const char* searchStr = nullptr;
		const char* targetStr = nullptr;

		while (*str1 != '\0')
		{
			searchStr = str1;
			targetStr = str2;

			while (*searchStr != '\0' && *targetStr != '\0' && *searchStr == *targetStr) 
			{
				searchStr++;
				targetStr++;
				
				if (*targetStr == '\0')
				{
					return str1;
				}
			}
			str1++;
		}
		return nullptr;
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