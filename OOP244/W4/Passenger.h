// Workshop 4, in lab.
// Name: Citlalli Melody Mastache
// Student #: 126275189
// Course: OOP244 Fall 2018
// File: Passenger.h

#ifndef PASSENGER_H
#define PASSENGER_H

#define CHARMAX 19

namespace sict {
	class Passenger {
		char p_name[CHARMAX + 1];
		char destination[CHARMAX + 1];

	public:
		Passenger(void);
		Passenger(const char *, const char *);
		bool isEmpty() const;
		void display() const;
	};
}

#endif
