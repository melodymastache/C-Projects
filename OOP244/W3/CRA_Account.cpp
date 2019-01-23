// Student Name: Citlalli Melody Mastache
// Student #: 126275189
// Course: OOP244 Fall 2018
// File: CRA_Account.cpp

#include <iostream>

#include <cstring>

#include "CRA_Account.h"

using namespace std;

namespace sict {

	// checks if sin is valid against max and min limits, stores empty state if not

	void CRA_Account::set(const char* family, const char* given, int SIN) {

		if (SIN > max_sin || SIN < min_sin) {

			this->SIN = 0; // storing empty state 

		}

		else { // storing family and given names along with sin

			strncpy(familyName, family, max_name_length);

			strncpy(givenName, given, max_name_length);

			familyName[max_name_length] = '\0';

			givenName[max_name_length] = '\0';

			this->SIN = SIN;

		}

	}

	bool CRA_Account::isEmpty() const {

		return SIN == 0;

	}

	void CRA_Account::display() const {

		if (!isEmpty()) {

			cout << "Family Name: " << this->familyName << endl;

			cout << "Given Name : " << this->givenName << endl;

			cout << "CRA Account: " << this->SIN << endl;

		}

		else {

			cout << "Account object is empty!" << endl;

		}

	}

}
