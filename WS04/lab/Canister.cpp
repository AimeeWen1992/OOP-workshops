///////////////////////////////////////////////////
// Workshop 4  : Canister.cpp
// Student Name: Rong-Yuan, Wen
// Student ID  : 114556228
// Email       : rwen1@myseneca.ca
// Section     : NGG
/////////////////////////////////////////////////// 

#define _CRT_SECURE_NO_WARNINGS
#include <istream>
#include <iomanip>
#include "cstring.h"
#include "Canister.h"
using namespace std;
#define PI 3.14159265
namespace sdds {
	void Canister::setToDefault(){
		m_contentName = nullptr;
		m_diameter = 10.0;
		m_height = 13.0;
		m_contentVolume = 0.0;
		m_usable = true;
	}

	void Canister::setName(const char* Cstr){
		if (Cstr != nullptr && m_usable){
			delete[] m_contentName;
			int length = strLen(Cstr);
			m_contentName = new char[length + 1];
			strCpy(m_contentName, Cstr);
		}
	}

	bool Canister::isEmpty() const{
		return m_contentVolume < 0.00001 ? true : false;
	}

	bool Canister::hasSameContent(const Canister& C) const{
		bool outcome = false;
		if(&C.m_contentName != nullptr && m_contentName != nullptr){
			outcome = strCmp(m_contentName, C.m_contentName) == 0 ? true : false;
		}
		return outcome;
	}

	Canister::Canister(){
		setToDefault();
	}

	Canister::Canister(const char* contentName){
		setToDefault();
		setName(contentName);
	}

	Canister::Canister(double height, double diameter, const char* contentName){
		setToDefault();
		if (height < 10.0 || height > 40.0 || diameter < 10.0 || diameter > 30){
			m_usable = false;
		}
		else{
			m_height = height;
			m_diameter = diameter;
			setName(contentName);
		}
	}

	Canister::~Canister(){
		delete [] m_contentName;
	}

	Canister& Canister::setContent(const char* contentName){
		if (contentName == nullptr){
			m_usable = false;
		}
		else if (isEmpty()){
			setName(contentName);
		}
		else if (!hasSameContent(contentName)){
			m_usable = false;
		}
		return *this;
	}

	Canister& Canister::pour(double quantity){
		if (quantity > 0.0 && this->m_usable && quantity + this->m_contentVolume <= capacity())
		{
			m_contentVolume += quantity;
		}
		else
		{
			m_usable = false;
		}
		return *this;
	}

	Canister& Canister::pour(Canister& C){

		setContent(C.m_contentName); 

		if (C.m_contentVolume > this->capacity() - this->m_contentVolume){ 
			C.m_contentVolume -= this->capacity() - this->m_contentVolume;
			this->m_contentVolume = capacity();
		}
		else{
			pour(C.m_contentVolume);
			C.m_contentVolume = 0.0;
		}
		return *this;
	}

	double Canister::volume() const{
		return m_contentVolume;
	}

	std::ostream& Canister::display() const{
		cout << fixed << setprecision(1) << setw(7) << capacity() 
				<< "cc (" << m_height << "x" << m_diameter << ") Canister";
		if (!m_usable){
			cout << " of Unusable content, discard!";
		}
		else if (m_contentName != nullptr) {
			cout << " of " << fixed << setprecision(1) << right << setw(7)  << m_contentVolume << "cc   " << m_contentName;
		}
		return cout;
	}
	double Canister::capacity() const{
		return PI * (m_height - 0.267) * (m_diameter / 2) * (m_diameter / 2);
	}

	void Canister::clear(){
		delete[] m_contentName;
		m_contentName = nullptr;
		m_contentVolume = 0.0;
		m_usable = true;
	}
}
