/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop  Part 2
// Version 1.0
// Description
// professor's tester program
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Aimee           5/25/2023 
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include "Employee.h"
using namespace sdds;
int main() {
   if (load()) {
       display();
   }
   deallocateMemory();
   return 0;
}