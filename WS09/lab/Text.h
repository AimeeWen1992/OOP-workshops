///////////////////////////////////////////////////
// Workshop 9  : Text.h
// Student Name: Rong-Yuan, Wen
// Student ID  : 114556228
// Email       : rwen1@myseneca.ca
// Section     : NGG
///////////////////////////////////////////////////
#ifndef SDDS_TEXT_H__
#define SDDS_TEXT_H__
#include <iostream>
namespace sdds {
   class Text {
      char* m_filename ;
      char* m_content ;
      int getFileLength()const;
   protected:
       // Provide read-only access to the content of the text
      const char& operator[](int index)const;
   public:
      // Construter
      Text(const char* filename=nullptr);
      // Rule of three
      ~Text();
      Text(const Text& other);
      Text& operator = (const Text& other);
      
      void read();
      virtual void write(std::ostream& os)const;
   };
   std::ostream& operator<<(std::ostream& os, const Text& text);
}
#endif // !SDDS_TEXT_H__

