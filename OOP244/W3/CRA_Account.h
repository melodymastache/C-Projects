// Student Name: Citlalli Melody Mastache
// Student #: 126275189
// Course: OOP244 Fall 2018
// File: CRA_Account.h

#ifndef CRA_ACCOUNT_H

#define CRA_ACCOUNT_H

#include <iostream>

using namespace std;

namespace sict {

	const int max_name_length = 40, min_sin = 100000000, max_sin = 999999999;

	class CRA_Account {

		char familyName[max_name_length + 1];

		char givenName[max_name_length + 1];

		int SIN;

	public:

		void set(const char*, const char*, int);

		bool isEmpty() const;

		void display() const;

	};

}

#endif
