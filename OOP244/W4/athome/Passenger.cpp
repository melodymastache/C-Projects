// Workshop 4, at home.
// Name: Citlalli Melody Mastache
// Student #: 126275189
// Course: OOP244 Fall 2018
// File: Passenger.cpp

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include "Passenger.h"
using namespace std;

namespace sict {
	Passenger::Passenger()
	{
		p_name[0] = '\0';
		destination[0] = '\0';
		day = 0;
		month = 0;
		year = 0;
	}

	Passenger::Passenger(const char * name, const char * dest) 
	{
		if (name == nullptr || dest == nullptr) {
			*this = Passenger();
		}
		else {
			strncpy(this->p_name, name, CHARMAX);
			p_name[CHARMAX] = '\0';
			strncpy(this->destination, dest, CHARMAX);
			destination[CHARMAX] = '\0';
			year = 2018;
			month = 10;
			day = 1;
		}
	}

	Passenger::Passenger(const char* name, const char* dest, int year, int month, int day) {
		if (year == 0 || month == 0 || day == 0 || name == nullptr || dest == nullptr) {
			*this = Passenger();
		}
		else if ((year == 2018 || year == 2019 || year == 2020) && (month >= 1 && month <= 12) && (day >= 1 && day <= 31)) {
			strncpy(this->destination, dest, CHARMAX);
			destination[CHARMAX] = '\0';
			strncpy(this->p_name, name, CHARMAX);
			p_name[CHARMAX] = '\0';
			this->year = year;
			this->month = month;
			this->day = day;
		}

	}

	bool Passenger::isEmpty(void) const
	{
		return !(strlen(p_name) > 0 && strlen(destination) > 0);
	}

	const char * Passenger::name() const {
			return p_name;
	}

	bool Passenger::canTravelWith(const Passenger & passenger) const {
		if (this->year == passenger.year && this->month == passenger.month && this->day == passenger.day) {
			return true;
		}
		else {
		return false;
		}
	}

	void Passenger::display(void) const
	{
		if (isEmpty()) {
			cout << "No passenger!" << endl;
		}
		else if (month > 0 && month < 10) {
			cout << p_name << " - " << destination << " on " << year << month << day << endl;
		}
		else if (day > 0 && day < 10)
		{

			cout << p_name << " - " << destination << " on " << year << "/" << month << "/0" << day << endl;
		}
		else if (day > 0 && day < 10 && month > 0 && month < 10)
		{

			cout << p_name << " - " << destination << " on " << year << "/0" << month << "/0" << day << endl;
		}
		else
		{
			cout << p_name << " - " << destination << " on " << year << "/" << month << "/" << day << endl;

		}
	}
}
