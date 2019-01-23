// Workshop 6, at home
// Name: Citlalli Melody Mastache
// Student #: 126275189
// Course: OOP244 Fall 2018
// File: Contact.h


#ifndef SICT_CONTACT_H
#define SICT_CONTACT_H
#include <iostream>

namespace sict {
	const int MAX_CHAR = 20;

	class Contact {
		char contactName[MAX_CHAR + 1];
		long long * phoneNums = nullptr;
		int currentNums;
		int* breakNum(long long) const;

	public:
		Contact();
		Contact(const char *, const long long *, const int);
		~Contact();
		Contact(const Contact&);
		Contact& operator=(const Contact&);
		Contact& operator+=(long long);
		bool valid(long long) const;

		bool isEmpty() const;
		void display() const;
	};
}
#endif
