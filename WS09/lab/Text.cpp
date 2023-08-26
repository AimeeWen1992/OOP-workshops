///////////////////////////////////////////////////
// Workshop 9  : Text.cpp
// Student Name: Rong-Yuan, Wen
// Student ID  : 114556228
// Email       : rwen1@myseneca.ca
// Section     : NGG
///////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include "Text.h"
#include "cstring.h"
using namespace std;
namespace sdds {
   int Text::getFileLength() const {
      int len = 0;
      ifstream fin(m_filename);
      while (fin) {
         fin.get();
         len += !!fin;
      }
      return len;
   }

   const char& Text::operator[](int index) const
   {
       return m_content[index];
   }

   Text::Text(const char* filename) : m_filename(nullptr), m_content(nullptr)
   {
       if (filename) {
           m_filename = new char[strLen(filename) + 1];
           strCpy(m_filename, filename);
           read();
       }
   }

   Text::~Text()
   {
       delete[]m_filename;
       delete[]m_content;
       m_filename = nullptr;
       m_content = nullptr;
   }

   Text::Text(const Text& other) : m_filename(nullptr), m_content(nullptr)
   {
       if (other.m_filename) 
       {
           m_filename = new char[strLen(other.m_filename) + 1];
           strCpy(m_filename, other.m_filename);
           read();
       }
   }

   Text& Text::operator=(const Text& other)
   {
       if (this != &other) 
       {
           delete[] m_filename;
           delete[] m_content;
           m_filename = nullptr;
           m_content = nullptr;

           if (other.m_filename) 
           {
               m_filename = new char[strLen(other.m_filename) + 1];
               strCpy(m_filename, other.m_filename);
               read();
           }
       }
       return *this;
   }

   void Text::read()
   {
       int len = getFileLength();
       if (len > 0)
       {
           m_content = new char [len + 1];
           std::ifstream file(m_filename);
           if (file.is_open()) {
               file.read(m_content, len);
               m_content[len] = '\0'; // Null-terminate
               file.close();
           }
       }

   }

   void Text::write(std::ostream& os) const
   {
       if (m_content) 
       {
           os << m_content;
       }
   }

   std::ostream& operator<<(std::ostream& os, const Text& text)
   {
       text.write(os);
       return os;
   }

}