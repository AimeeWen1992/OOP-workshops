///////////////////////////////////////////////////
// Workshop 7  : Truck.h
// Student Name: Rong-Yuan, Wen
// Student ID  : 114556228
// Email       : rwen1@myseneca.ca
// Section     : NGG
///////////////////////////////////////////////////
#ifndef SDDS_TRUCK_H
#define SDDS_TRUCK_H
#include"MotorVehicle.h"

namespace sdds {
	class Truck : public MotorVehicle {
	private:
		double m_maxWeight;
		double m_currentWeight;
	public:
		Truck(const char* plateNum, int buildYear, double maxWeight, const char* address);
		bool addCargo(double cargo);
		bool unloadCargo();
		std::ostream& write(std::ostream& os)const;
		std::istream& read(std::istream& in);
	};
	std::ostream& operator<<(std::ostream& os, const Truck& truck);
	std::istream& operator>>(std::istream& in, Truck& truck);

}
#endif // !SDDS_TRUCK_H
