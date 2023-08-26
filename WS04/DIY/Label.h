///////////////////////////////////////////////////
// Workshop 4  : Label.h
// Student Name: Rong-Yuan, Wen
// Student ID  : 114556228
// Email       : rwen1@myseneca.ca
// Section     : NGG
///////////////////////////////////////////////////
#pragma once
#ifndef SDDS_LABEL_H
#define SDDS_LABEL_H

//#include <iostream>

namespace sdds {

	class Label
	{
	private:
		char m_frame[8+1];
		char* m_content;
	public:
		void setDefault();
		Label();
		~Label();
		Label(const char* frameArg);
		Label(const char* frameArg, const char* content);
		void readLabel();
		std::ostream& printLabel()const;
	};
}
#endif // !SDDS_LABEL_H



