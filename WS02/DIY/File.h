///////////////////////////////////////////////////
// Workshop 2  : File.h
// Student Name: Rong-Yuan, Wen
// Student ID  : 114556228
// Email       : rwen1@myseneca.ca
// Section     : NGG
///////////////////////////////////////////////////
#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_

#include<string>
using namespace std;
namespace sdds {
   bool openFile(const char filename[]);
   void closeFile();
   int noOfRecords();
   bool read(char poatalCode[]);
   bool read(int& populationNo);
}
#endif // !SDDS_FILE_H_
