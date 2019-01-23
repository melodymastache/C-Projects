// Workshop 4, in lab.
// Name: Citlalli Melody Mastache
// Student #: 126275189
// Course: OOP244 Fall 2018
// File: Passenger.cpp

#include <iostream>
#include <cstring>
#include "Passenger.h"
using namespace std;

namespace sict {
	Passenger::Passenger()
	{
		p_name[0] = '\0';
		destination[0] = '\0';
	}

	Passenger::Passenger(const char * name, const char * dest) 
	{
		if (name == nullptr || dest == nullptr) {
			*this = Passenger();
		}
		else {
			strncpy(this->p_name, name, CHARMAX);
			p_name[CHARMAX - 1] = '\0';
			strncpy(this->destination, dest, CHARMAX);
			destination[CHARMAX - 1] = '\0';
		}
	}

	bool Passenger::isEmpty(void) const
	{
		return !(strlen(p_name) > 0 && strlen(destination) > 0);
	}

	void Passenger::display(void) const
	{
		bool empty = isEmpty();
		if (empty) {
			cout << "No passenger!" << endl;
		}
		else {
			cout << p_name << " - " << destination << endl;
		}
	}
}
