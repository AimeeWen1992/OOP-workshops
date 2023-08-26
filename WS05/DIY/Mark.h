///////////////////////////////////////////////////
// Workshop 5  : Mark.h
// Student Name: Rong-Yuan, Wen
// Student ID  : 114556228
// Email       : rwen1@myseneca.ca
// Section     : NGG
///////////////////////////////////////////////////

#pragma once
#ifndef SDDS_MARK_H
#define SDDS_MARK_H

namespace sdds 
{
    class Mark 
    {
        int m_mark;
        bool isVaild;
        void setEmpty();
    public:
        Mark();
        Mark(int mark);

        bool operator~() const;

        operator bool() const;
        operator int() const;
        operator double() const;
        operator char() const;

        Mark& operator=(int mark);
        Mark& operator+=(int mark);
    };

    int operator+=(int& value, Mark other);
}
#endif // !SDDS_MARK_H
