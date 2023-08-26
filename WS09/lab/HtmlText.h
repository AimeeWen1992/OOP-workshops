///////////////////////////////////////////////////
// Workshop 9  : HtmlText.h
// Student Name: Rong-Yuan, Wen
// Student ID  : 114556228
// Email       : rwen1@myseneca.ca
// Section     : NGG
///////////////////////////////////////////////////
#ifndef SDDS_HTMLTEXT_H__
#define SDDS_HTMLTEXT_H__
#include "Text.h"
namespace sdds {
   class HtmlText : public Text {
      char* m_title;
   public:
      HtmlText(const char* filename=nullptr, const char* title = nullptr);
      // Rule of three
      ~HtmlText();
      HtmlText(const HtmlText& other);
      HtmlText& operator=(const HtmlText& other);

      void write(std::ostream& os)const override;

   };
   std::ostream& operator<<(std::ostream& os, const sdds::HtmlText& htmlText);

}
#endif // !SDDS_HTMLTEXT_H__
