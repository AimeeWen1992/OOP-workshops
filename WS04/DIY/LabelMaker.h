///////////////////////////////////////////////////
// Workshop 4  : LabelMaker.h
// Student Name: Rong-Yuan, Wen
// Student ID  : 114556228
// Email       : rwen1@myseneca.ca
// Section     : NGG
///////////////////////////////////////////////////
#pragma once
#ifndef SDDS_LABEL_MAKER_H
#define SDDS_LABEL_MAKER_H

#include "Label.h"

namespace sdds {
	class LabelMaker
	{
	private:
		Label* labels;
		int m_noOfLabels;
	public:
		LabelMaker();
		~LabelMaker();
		LabelMaker(int noOfLabels);
		void readLabels();
		void printLabels();
		
	};
}
#endif // !SDDS_LABEL_MAKER_H
