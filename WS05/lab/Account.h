///////////////////////////////////////////////////
// Workshop 4  : Account.h
// Student Name: Rong-Yuan, Wen
// Student ID  : 114556228
// Email       : rwen1@myseneca.ca
// Section     : NGG
///////////////////////////////////////////////////

#ifndef SDDS_ACCOUNT_H_
#define SDDS_ACCOUNT_H_
#include <iostream>

namespace sdds {
   class Account {
      int m_number;
      double m_balance; 
      void setEmpty();
   public:
      Account();
      Account(int number, double balance);
      std::ostream& display()const;

      // Unary member operator
      bool operator~() const;

      // Type conversion operators
      operator bool() const;
      operator int() const;
      operator double() const;

      // Binary member operators
      Account& operator=(int number);
      Account& operator=(Account& other);
      Account& operator+=(double amount);
      Account& operator-=(double amount);
      Account& operator<<(Account& other);
      Account& operator>>(Account& other);

   };
   
   // Binary helper operators
   double operator+(const Account& leftAcc, const Account& rightAcc);
   double operator+=(double& amount, const Account& other);
}
#endif // SDDS_ACCOUNT_H_