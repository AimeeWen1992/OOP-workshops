///////////////////////////////////////////////////
// Workshop 9  : HtmlText.cpp
// Student Name: Rong-Yuan, Wen
// Student ID  : 114556228
// Email       : rwen1@myseneca.ca
// Section     : NGG
///////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include "HtmlText.h"
#include "cstring.h"
namespace sdds {
	HtmlText::HtmlText(const char* filename, const char* title) : Text(filename) {
        // Dynamically allocate memory for the title if it is not null
        if (title)
        {
            m_title = new char[strLen(title) + 1];
            strCpy(m_title, title);
        }
        else 
        {
            m_title = nullptr;
        }
    }

    HtmlText::~HtmlText()
    {
        delete[] m_title;
        m_title = nullptr;
    }

    HtmlText::HtmlText(const HtmlText& other) :Text(other), m_title(nullptr)
    {
        if (other.m_title)
        {
            m_title = new char[strLen(other.m_title) + 1];
            strCpy(m_title, other.m_title);
        }
    }

    HtmlText& HtmlText::operator=(const HtmlText& other)
    {
        if (this != &other)
        {
            // Call base class's assignment operator
            Text::operator=(other);

            delete[] m_title;
            m_title = nullptr;

            if (other.m_title)
            {
                m_title = new char[strLen(other.m_title) + 1];
                strCpy(m_title, other.m_title);
            }
            else
            {
                m_title = nullptr;
            }
        }
        return *this;
    }

    void HtmlText::write(std::ostream& os) const
    {
        bool multipleSpaces = false;
        os << "<html><head><title>";
        os << (m_title ? m_title : "No Title");
        os << "</title></head>\n<body>\n";
        if (m_title)
        {
            os << "<h1>" << m_title << "</h1>\n";

            for (int i = 0; operator[](i) != '\0'; i++)
            {
                char character = (*this)[i];
                switch (character)
                {
                case ' ':
                    if (multipleSpaces)
                    {
                        os << "&nbsp;";
                    }
                    else
                    {
                        os << ' ';
                        multipleSpaces = true;
                    }
                    break;
                case '<':
                    os << "&lt;";
                    multipleSpaces = false;
                    break;
                case '>':
                    os << "&gt;";
                    multipleSpaces = false;
                    break;
                case '\n':
                    os << "<br />\n";
                    multipleSpaces = false;
                    break;
                default:
                    os << character;
                    multipleSpaces = false;
                    break;
                }
            }
        }
        os << "</body>\n</html>";
    }
    
    std::ostream& operator<<(std::ostream& os, const sdds::HtmlText& htmlText)
    {
        htmlText.write(os);
        return os;
    }
}