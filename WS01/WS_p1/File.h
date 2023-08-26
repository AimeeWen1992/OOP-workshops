///////////////////////////////////////////////////
// Workshop 1  : File.h
// Student Name: Rong-Yuan, Wen
// Student ID  : 114556228
// Email       : rwen1@myseneca.ca
// Section     : NGG
///////////////////////////////////////////////////

#ifndef SDDS_FILE_H 
#define SDDS_FILE_H

#include "ShoppingRec.h"

namespace sdds {
	bool openFileForRead();

	bool openFileForOverwrite();

	void closeFile();

	bool freadShoppingRec(ShoppingRec* rec);

	void fwriteShoppintRec(const ShoppingRec* rec);
}

#endif