// Milestone 5
// Name: Citlalli Melody Mastache
// Student #: 126275189
// Course: OOP244 Fall 2018
// File: Perishable.cpp

#include <iostream>
#include <fstream>
#include "Date.h"
#include "Perishable.h"
#include "Error.h"

namespace aid {
	// sets empty state of date, identifies good as perishable
	Perishable::Perishable() : Good('P') {
		date = Date();
	}
	// stores record for current obj
	std::fstream& Perishable::store(std::fstream& fs, bool newLine) const {
		Good::store(fs, false);
		fs << "," << expiry();
		if (newLine) {
			fs << '\n';
		}
		return fs;
	}
	// extracts data from good class, and expiry date from date class
	std::fstream& Perishable::load(std::fstream& fs) {
		int y, m, d;
		char c;

		Good::load(fs);

		fs >> c;
		fs >> y >> c;
		fs >> m >> c;
		fs >> d;
		
		Date t(y, m, d);
		date = t;

		return fs;
	}
	// writes to screen the details of the current object
	std::ostream& Perishable::write(std::ostream& os, bool linear) const {
		Good::write(os, linear);
		if (isClear() && !isEmpty()) {
			if (linear) {
				os << expiry();
			}
			else {
				os << "\n Expiry date: ";
				os << expiry();
			}
		}
		return os;
	}
	// reads date from input stream and sets error message if input is incorrect
	std::istream& Perishable::read(std::istream& is) {
		Good::read(is);
		if (!is.fail()) {
			std::cout << " Expiry date (YYYY/MM/DD): ";
			is >> date;
			if (date.errCode() != NO_ERROR) {
				switch (date.errCode()) {
				case CIN_FAILED:
					is.setstate(std::ios::failbit);
					Good::message("Invalid Date Entry");
					break;
				case YEAR_ERROR:
					is.setstate(std::ios::failbit);
					Good::message("Invalid Year in Date Entry");
					break;
				case MON_ERROR:
					is.setstate(std::ios::failbit);
					Good::message("Invalid Month in Date Entry");
					break;
				case DAY_ERROR:
					is.setstate(std::ios::failbit);
					Good::message("Invalid Day in Date Entry");
					break;
				case PAST_ERROR:
					is.setstate(std::ios::failbit);
					Good::message("Invalid Expiry in Date Entry");
					break;
				default:
					break;
				}
			}
		}
		return is;
	}
	// returns date
	const Date& Perishable::expiry() const {
		return date;
	}
}
