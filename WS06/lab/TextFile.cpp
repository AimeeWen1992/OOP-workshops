///////////////////////////////////////////////////
// Workshop 6  : TextFile.cpp
// Student Name: Rong-Yuan, Wen
// Student ID  : 114556228
// Email       : rwen1@myseneca.ca
// Section     : NGG
///////////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include <string>
#include "TextFile.h"
#include "cstring.h"
using namespace std;
namespace sdds {
    Line::operator const char* () const {
        return (const char*)m_value;
    }
    Line& Line::operator=(const char* lineValue) {
        delete[] m_value;
        m_value = new char[strLen(lineValue) + 1];
        strCpy(m_value, lineValue);
        return *this;
    }
    Line::~Line() {
        delete[] m_value;
    }

    void TextFile::setFilename(const char* fname, bool isCopy) {
       
            delete[] m_filename;
            m_filename = nullptr;
            if (isCopy == true)
            {
                m_filename = new char[strLen(fname) + 3];
                strCpy(m_filename, "C_");
                strCat(m_filename, fname);
            }
            else
            {
                m_filename = new char[strLen(fname) + 1];
                strCpy(m_filename, fname);
            }
    }

    void TextFile::setNoOfLines() {
        std::ifstream file;
        file.open(m_filename);
        char c;
        if (file) {
            while (file.get(c)) {
                if (c == '\n') {
                    m_noOfLines++;
                }
            }
        }

        if (m_noOfLines == 0) {
            delete[] m_filename;
            m_filename = nullptr;
        }
        else {
            m_noOfLines++;
        }
    }

    void TextFile::loadText() {
        if (m_filename) {
            ifstream file(m_filename);
            string line;
            unsigned i = 0;
            delete[] m_textLines;
            m_textLines = new Line[m_noOfLines];
            while (getline(file, line)) {
                m_textLines[i] = line.c_str();
                i++;
            }
            m_noOfLines = i;
            file.close();
        }
    }

    void TextFile::saveAs(const char* fileName)const {
        std::ofstream outputFile(fileName);
        for (unsigned i = 0; i < m_noOfLines; i++) {
            outputFile << m_textLines[i] << '\n';
        }
        outputFile.close();
    }

    void TextFile::setEmpty() {
        delete[] m_textLines;
        m_textLines = nullptr;
        delete[] m_filename;
        m_filename = nullptr;
        m_noOfLines = 0;
    }

//----------------------------------------------------------

    TextFile::TextFile(unsigned pageSize) {
        m_textLines = nullptr;
        m_filename = nullptr;
        m_noOfLines = 0;
        m_pageSize = pageSize;
    }

    TextFile::TextFile(const char* filename, unsigned pageSize) {
        m_textLines = nullptr;
        m_filename = nullptr;
        m_noOfLines = 0;
        m_pageSize = pageSize;
        if (filename != nullptr) {
            setFilename(filename);
            setNoOfLines();
            loadText();
        }
    }

    TextFile::TextFile(const TextFile& src) {
        m_pageSize = src.m_pageSize;
        m_textLines = nullptr;
        m_filename = nullptr;
        m_noOfLines = 0;

        if (src.m_filename != nullptr) {
            setFilename(src.m_filename, true);
            src.saveAs(m_filename);
            setNoOfLines();
            loadText();
        }
    }

    TextFile& TextFile::operator=(const TextFile& text) {

        if (this != &text && text && *this) {
            delete[] m_textLines;
            m_textLines = nullptr;
            text.saveAs(m_filename);
            setNoOfLines();
            loadText();
        }

        return *this;

    }

    TextFile:: ~TextFile() {
        setEmpty();
    }

    std::ostream& TextFile::view(std::ostream& ostr) const {

        if (m_filename) {
            ostr << m_filename << endl;
            ostr.width(strLen(m_filename));
            ostr.fill('=');
            ostr << "=" << endl;
            ostr.fill(' ');
            
            for (unsigned int i = 0; i < m_noOfLines; i++) {
                ostr << (*this)[i] << endl;
                if ((i + 1) % m_pageSize == 0) {
                    ostr << "Hit ENTER to continue...";
                    cin.ignore(1000, '\n');
                }
            }
        }
        return ostr;

    }

    std::istream& TextFile::getFile(std::istream& istr) {
        string filename;
        istr >> filename;
        while (getchar() != '\n');
        setFilename(filename.c_str());
        setNoOfLines();
        loadText();
        return istr;
    }

    TextFile:: operator bool()const {
        return (m_filename != nullptr);
    }

    unsigned TextFile::lines()const {
        return m_noOfLines;
    }

    const char* TextFile::name()const {
        return m_filename;
    }

    const char* TextFile::operator[](unsigned index)const {
        const char* line = m_textLines[index % m_noOfLines];
        return (*this) ? line : nullptr;
    }

//----------------------------------------------------------

    std::ostream& operator<<(std::ostream& ostr, const TextFile& text) {
        return text.view(ostr);
    }
    std::istream& operator>>(std::istream& istr, TextFile& text) {
        return text.getFile(istr);
    }
}