///////////////////////////////////////////////////
// Workshop 4  : Label.cpp
// Student Name: Rong-Yuan, Wen
// Student ID  : 114556228
// Email       : rwen1@myseneca.ca
// Section     : NGG
///////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Label.h"
#include "cstring.h"
using namespace std;
namespace sdds {
	void Label::setDefault()
	{
		strnCpy(m_frame, "+-+|+-+|", 9);
		this->m_content = nullptr;
	}
	Label::Label()
	{
		setDefault();
	}

	Label::~Label()
	{
        delete[] m_content;
	}
	Label::Label(const char* frameArg)
	{
		setDefault();
		strnCpy(m_frame, frameArg, strLen(frameArg) + 1);
	}

	Label::Label(const char* frameArg, const char* content)
	{
		setDefault();
		strnCpy(m_frame, frameArg, strLen(frameArg) + 1);
		m_content = new char[strLen(content) + 1];
		strCpy(m_content, content);
	}

	void Label::readLabel()
	{
        char temp[70 + 1];
        cin.getline(temp, 71);
		delete[] m_content;
		m_content = new char[strLen(temp) + 1];
		strCpy(m_content, temp);
	}
   
	std::ostream& Label::printLabel() const
	{
        char dash = '-';
        int len = m_content == nullptr ? 0 : strLen(m_content) + 2;

		if (m_frame != nullptr && m_content != nullptr)
		{
            for (int i = 0; i < 5; i++)
            {
                if (i == 0 || i == 4)
                {
                    switch (m_frame[i])
                    {
                    case '+':
                        cout << m_frame[i];
                        break;

                    default:
                        i == 0 ? cout << m_frame[i] : cout << m_frame[i + 2];
                        break;
                    }
                    for (int j = 0; j < len; j++)
                    {
                        cout << dash;
                    }
                    switch (m_frame[i])
                    {
                    case '+':
                        cout << "+" << endl;
                        break;
                    default:
                        i == 4 ? cout << m_frame[i] : cout << m_frame[i + 2] << endl;
                        break;
                    }
                }
                else if (i == 2)
                {
                    cout << "| " << m_content << " |" << endl;
                }
                else {
                    cout << '|';
                    for (int j = 0; j < len; j++)
                    {
                        cout << " ";
                    }
                    cout << '|' << endl;
                }
            }
		}
		return cout;
	}

}