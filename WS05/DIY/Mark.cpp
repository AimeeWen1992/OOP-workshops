///////////////////////////////////////////////////
// Workshop 5  : Mark.cpp
// Student Name: Rong-Yuan, Wen
// Student ID  : 114556228
// Email       : rwen1@myseneca.ca
// Section     : NGG
///////////////////////////////////////////////////

#include<iostream>
#include "Mark.h"

const int minMark = 0;
const int maxMark = 100;

using namespace std;

namespace sdds {

    void Mark::setEmpty() 
    {
        m_mark = 0;
        isVaild = false;
    }

    Mark::Mark() 
    {
        m_mark = 0;
        isVaild = true;
    }

    Mark::Mark(int mark)
    {
        if (mark >= minMark && mark <= maxMark) 
        {
            m_mark = mark;
            isVaild = true;
        }
        else 
        {
            setEmpty();
        }
    }

    bool Mark::operator~() const
    {
        return isVaild ? true : false;
    }

    Mark::operator bool() const
    {
        return (m_mark >= minMark && m_mark <= maxMark && isVaild) ? true : false;
    }

    Mark::operator int() const 
    {
        int mark = 0;
        if (*this)
        {
            mark = m_mark;
        }
        return mark;
    }

    Mark::operator double() const
    {
        double gpa = 0.0;
        if (~*this)
        {
            if (m_mark > -1 && m_mark < 50)
            {
                gpa = 0.0;
            }
            else if (m_mark > 49 && m_mark < 60) 
            {
                gpa = 1.0;
            }
            else if (m_mark > 59 && m_mark < 70)
            {
                gpa = 2.0;
            }
            else if (m_mark > 69 && m_mark < 80)
            {
                gpa = 3.0;
            }
            else if (m_mark > 79 && m_mark < 101)
            {
                gpa = 4.0;
            }
        }
        return gpa;
    }

    Mark:: operator char() const
    {
        char grade = 'X';
        if (~*this)
        {
            if (m_mark > -1 && m_mark < 50)
            {
                grade = 'F';
            }
            else if (m_mark > 49 && m_mark < 60)
            {
                grade = 'D';
            }
            else if (m_mark > 59 && m_mark < 70) 
            {
                grade = 'C';
            }
            else if (m_mark > 69 && m_mark < 80) 
            {
                grade = 'B';
            }
            else if (m_mark > 79 && m_mark < 101)
            {
                grade = 'A';
            }
        }
        return grade;
    }

    Mark& Mark:: operator=(int mark) {
        m_mark = mark;
        if (m_mark >= minMark && m_mark <= maxMark) 
        {
            isVaild = true;
        }
        else
        {
            setEmpty();
        }
        return *this;
    }

    Mark& Mark:: operator+=(int mark)
    {
        if (~*this) 
        {
            m_mark += mark;
        }
        else
        {
            setEmpty();
        }
        return *this;
    }

    int operator+=(int& value, Mark other)
    {
        int ret;
        ret = value + int(other);
        value = ret;
        return ret;
    }
}