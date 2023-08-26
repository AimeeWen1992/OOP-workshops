///////////////////////////////////////////////////
// Workshop 2  : File.cpp
// Student Name: Rong-Yuan, Wen
// Student ID  : 114556228
// Email       : rwen1@myseneca.ca
// Section     : NGG
///////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

namespace sdds {

   FILE* fptr;
   bool openFile(const char filename[])
   {
      fptr = fopen(filename, "r");
      return fptr != NULL;
   }

   int noOfRecords()
   {
      int noOfRecs = 0;
      char ch;
      while (fscanf(fptr, "%c", &ch) == 1)
      {
         noOfRecs += (ch == '\n');
      }
      rewind(fptr);
      return noOfRecs;
   }

   void closeFile() 
   {
      if (fptr) fclose(fptr);
   }

   bool read(char* m_name) {
       int outcome = fscanf(fptr, "%[^\n]\n", m_name);
       return (outcome == 0) ? false : true;
   }

   bool read(int& m_empNo) {
       int outcome = fscanf(fptr, "%d,", &m_empNo);
       return (outcome == 0) ? false : true;
   }

   bool read(double& m_salary) {
       int outcome = fscanf(fptr, "%lf,", &m_salary);
       return (outcome == 0) ? false : true;
   }

}