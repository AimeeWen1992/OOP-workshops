///////////////////////////////////////////////////
// Workshop 7  : MotorVehicle.cpp
// Student Name: Rong-Yuan, Wen
// Student ID  : 114556228
// Email       : rwen1@myseneca.ca
// Section     : NGG
///////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "MotorVehicle.h"
#include "cstring.h"
using namespace std;
namespace sdds {
	MotorVehicle::MotorVehicle(const char* plateNumber, int buildYear)
	{
		strnCpy(m_plateNum, plateNumber,strLen(plateNumber));
		m_buildYear = buildYear;
		strCpy(m_address, "Factory");
	}

	void MotorVehicle::moveTo(const char* address)
	{
		if (strCmp(m_address, address)) {
			cout << "|" << setw(8) << right << m_plateNum << "| " << "|"
				<< setw(20) << right << m_address << " ---> "
				<< setw(20) << left << address << "|" << endl;
			strnCpy(m_address, address, strLen(address));
		}
	}

	std::ostream& MotorVehicle::write(std::ostream& os)const
	{
		os << "| " << m_buildYear << " | " << m_plateNum << " | " << m_address;
		return os;
	}

	std::istream& MotorVehicle::read(std::istream& in)
	{
		cout << "Built year: ";
		in.clear();
		in >> m_buildYear;
		cout << "License plate: ";		
		in.ignore();
		in.getline(m_plateNum, maxPlateNum);
		//if error state then clear error state first and clear the buffer
		if (in.fail()) {
			in.clear();
			while (getchar() != '\n')
			{
				; // do nothing!
			}
		}
		cout << "Current location: ";
		in.getline(m_address, maxAdrressChar);
		if (in.fail()) {
			in.clear();
			while (getchar() != '\n')
			{
				; // do nothing!
			}
		}
		return in;
	}

	std::ostream& operator<<(std::ostream& os, const MotorVehicle& MV)
	{
		return MV.write(os);
	}

	std::istream& operator>>(std::istream& in, MotorVehicle& MV)
	{
		return MV.read(in);
	}

}