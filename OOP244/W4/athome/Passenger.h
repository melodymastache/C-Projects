// Workshop 4, at home.
// Name: Citlalli Melody Mastache
// Student #: 126275189
// Course: OOP244 Fall 2018
// File: Passenger.h

#ifndef PASSENGER_H
#define PASSENGER_H

#define CHARMAX 18

namespace sict {
	class Passenger {
		char p_name[CHARMAX + 1];
		char destination[CHARMAX + 1];
		int year, month, day;

	public:
		Passenger(void);
		Passenger(const char *, const char *);
		Passenger(const char *, const char *, int, int, int);
		const char * name(void) const;		
		bool isEmpty(void) const;
		void display(void) const;
		bool canTravelWith(const Passenger&) const;
	};
}

#endif
