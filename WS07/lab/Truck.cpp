///////////////////////////////////////////////////
// Workshop 7  : Truck.cpp
// Student Name: Rong-Yuan, Wen
// Student ID  : 114556228
// Email       : rwen1@myseneca.ca
// Section     : NGG
///////////////////////////////////////////////////
#include "Truck.h"
using namespace std;
namespace sdds {
	Truck::Truck(const char* plateNum, int buildYear, double maxWeight, const char* address):MotorVehicle(plateNum,buildYear)
	{
		m_maxWeight = maxWeight;
		m_currentWeight = 0.0;
		moveTo(address);
	}

	bool Truck::addCargo(double cargo)
	{
		bool result = false;
		if (m_currentWeight < m_maxWeight)
		{
			result = true;
			if (cargo + m_currentWeight <= m_maxWeight)
			{
				m_currentWeight += cargo;
			}
			else
			{
				m_currentWeight = m_maxWeight;
			}
		}
		return result;
	}

	bool Truck::unloadCargo()
	{
		bool result = false;
		if (m_currentWeight > 0.0)
		{
			m_currentWeight = 0.0;
			result = true;
		}
		return result;
	}

	std::ostream& Truck::write(std::ostream& os) const
	{
		MotorVehicle::write(os);
		os << " | " << m_currentWeight << "/" << m_maxWeight;
		return os;
	}
	std::istream& Truck::read(std::istream& in)
	{
		MotorVehicle::read(in);
		cout << "Capacity: ";
		in.clear();
		in >> m_maxWeight;
		in.clear();
		cout << "Cargo: ";
		in >> m_currentWeight;
		return in;
	}
	std::ostream& operator<<(std::ostream& os, const Truck& truck)
	{
		return truck.write(os);
	}
	std::istream& operator>>(std::istream& in, Truck& truck)
	{
		return truck.read(in);
	}
}