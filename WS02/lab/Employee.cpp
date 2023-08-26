///////////////////////////////////////////////////
// Workshop 2  : Employee.cpp
// Student Name: Rong-Yuan, Wen
// Student ID  : 114556228
// Email       : rwen1@myseneca.ca
// Section     : NGG
///////////////////////////////////////////////////

#include <iostream>
#include "cstring.h"
#include "Employee.h"
#include "File.h"
using namespace std;
namespace sdds {

   int noOfEmployees;
   Employee* employees;

   void sort()
   {
      int i, j;
      Employee temp;
      for (i = noOfEmployees - 1; i > 0; i--) 
      {
         for (j = 0; j < i; j++)
         {
            if (employees[j].m_empNo > employees[j + 1].m_empNo) 
            {
               temp = employees[j];
               employees[j] = employees[j + 1];
               employees[j + 1] = temp;
            }
         }
      }
   }


   bool load(Employee &singleEmploymee)
   {
      bool ok = false;
      char name[128];
      if (read(singleEmploymee.m_empNo) && read(singleEmploymee.m_salary) && read(name))
      {
          singleEmploymee.m_name = new char[strLen(name) + 1];
          strCpy(singleEmploymee.m_name, name);
          ok = true;
      }
      else
      {
          ok = false;
      }
      return ok;
   }
 
   bool load() 
   {
      bool ok = false;
      int i = 0;
      if (openFile(DATAFILE)) 
      {
          noOfEmployees = noOfRecords();
          employees = new Employee[noOfEmployees];
          
          for (i = 0; i < noOfEmployees; i++)
          {
              ok = load(employees[i]) == 0 ? false : true;
          }
          closeFile();
      }
      else 
      {
         cout << "Could not open data file: " << DATAFILE<< endl;
      }
      return ok;
   }

   void display(const Employee &singleEmploymee)
   {
       cout << singleEmploymee.m_empNo << ": " << singleEmploymee.m_name << ", " << singleEmploymee.m_salary << endl;
   }

   void display()
   {
       sort();
       cout << "Employee Salary report, sorted by employee number" << endl;
       cout << "no- Empno, Name, Salary" << endl;
       cout << "------------------------------------------------" << endl;

       for (int i = 0; i < noOfEmployees; i++)
       {
           cout << i + 1 << "- ";
           display(employees[i]);
       }
   }

   void deallocateMemory()
   {
       int i;
       for (i = 0; i < noOfEmployees; i++) 
       {
           delete[] employees[i].m_name;
       }
       delete[] employees;
       
       employees = nullptr;
   }

}