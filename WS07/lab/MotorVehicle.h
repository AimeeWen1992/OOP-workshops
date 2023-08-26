///////////////////////////////////////////////////
// Workshop 7  : MotorVehicle.h
// Student Name: Rong-Yuan, Wen
// Student ID  : 114556228
// Email       : rwen1@myseneca.ca
// Section     : NGG
///////////////////////////////////////////////////
#ifndef SDDS_MOTOT_VEHICLE_H
#define SDDS_MOTOT_VEHICLE_H
#include<iostream>

namespace sdds {
	const int maxPlateNum = 9;
	const int maxAdrressChar = 64;

	class MotorVehicle {
	private:
		char m_plateNum[maxPlateNum];
		char m_address[maxAdrressChar];
		int m_buildYear;
	public:
		// Assume all data is valid.
		MotorVehicle(const char* plateNumber, int buildYear);
		void moveTo(const char* address);
		std::ostream& write(std::ostream& os)const;
		std::istream& read(std::istream & in);
	};
	std::ostream& operator<<(std::ostream& os, const MotorVehicle& MV);
	std::istream& operator>>(std::istream& in, MotorVehicle& MV);
}

#endif // SDDS_MOTOT_VEHICLE_H
