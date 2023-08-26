///////////////////////////////////////////////////
// Workshop 4  : Account.cpp
// Student Name: Rong-Yuan, Wen
// Student ID  : 114556228
// Email       : rwen1@myseneca.ca
// Section     : NGG
///////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"

using namespace std;
namespace sdds {
   void Account::setEmpty() {
      m_number = -1;
      m_balance = 0.0;
   }
   // New account
   Account::Account() {  
      m_number = 0;
      m_balance = 0.0;
   }
   Account::Account(int number, double balance ) {
      setEmpty();
      if (number >= 10000 && number <= 99999
         && balance > 0) {
         m_number = number;
         m_balance = balance;
      }
   }
   std::ostream& Account::display() const{
      if (*this) {  
         cout << " ";
         cout << m_number;
         cout << " | ";
         cout.width(12);
         cout.precision(2);
         cout.setf(ios::right);
         cout.setf(ios::fixed);
         cout << m_balance;
         cout.unsetf(ios::right);
         cout << " ";
      }
      else if(~*this) {
         cout << "  NEW  |         0.00 ";
      }
      else {
         cout << "  BAD  |    ACCOUNT   ";
      }
      return cout;
   }

   //check if account is new
   bool Account::operator~() const
   {
       return m_number == 0? true : false;
   }

   //check if account is valid
   Account::operator bool() const
   {
       return m_number != -1 && m_number != 0 && m_balance >= 0 ? true : false;
   }

   Account::operator int() const
   {
       return m_number;
   }

   Account::operator double() const
   {
       return m_balance;
   }

   Account& Account::operator=(int number)
   {
       if (~(*this)) 
       {
           if (number >= 10000 && number <= 99999) 
           {
               this->m_number = number;
           }
           else 
           {
               this->setEmpty();
           }
       }
       return *this;
   }

   Account& Account::operator=(Account& other)
   {
       if (~(*this) && bool(other))
       {
           this->m_number = other.m_number;
           other.m_number = 0;
           this->m_balance = other.m_balance;
           other.m_balance = 0;
       }
       return *this;
   }

   Account& Account::operator+=(double amount)
   {
       if (bool(this) && amount > 0.0)
       {
           this->m_balance += amount;
       }
       return *this;
   }

   Account& Account::operator-=(double amount)
   {
       if (bool(this))
       {
           if (this->m_balance > amount && amount > 0.0)
           {
               this->m_balance -= amount;
           }
       }
       return *this;
   }

   Account& Account::operator<<(Account& other)
   {
       if (bool(this) && bool(other))
       {
           if (this->m_number != other.m_number)
           {
               this->m_balance += other.m_balance;
               other.m_balance -= other.m_balance;
           }
       }
       return *this;
   }

   Account& Account::operator>>(Account& other)
   {
       if(bool(this) && bool(other))
       {
           if (this->m_number != other.m_number)
           {
               other.m_balance += double(*this);
               this->m_balance -= double(*this);
           }
       }
       return *this;
   }

   double operator+(const Account& leftAcc, const Account& rightAcc)
   {
       double sum = 0.0;
       if (bool(leftAcc) && bool(rightAcc))
       {
           sum = double(leftAcc) + double(rightAcc);
       }
       return sum;
   }

   double operator+=(double& amount, const Account& other)
   {
       double ret;
       ret = amount + double(other);          
       amount = ret;
       return ret;
   }
}