// Milestone 5
// Name: Citlalli Melody Mastache
// Student #: 126275189
// Course: OOP244 Fall 2018
// File: Perishable.h

#ifndef AID_PERISHABLE_H
#define AID_PERISHABLE_H
#include <iostream>
#include <fstream>
#include "Date.h"
#include "Good.h"

namespace aid {
	class Perishable : public Good {
		Date date;
	public:
		Perishable();
		std::fstream& store(std::fstream&, bool newLine = true) const;
		std::fstream& load(std::fstream&);
		std::ostream& write(std::ostream&, bool) const;
		std::istream& read(std::istream&);
		const Date& expiry() const;
	};
}

#endif
