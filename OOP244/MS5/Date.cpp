// Milestone 5
// Name: Citlalli Melody Mastache
// Student #: 126275189
// Course: OOP244 Fall 2018
// File: Date.cpp

#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include "Date.h"

namespace aid {

	// number of days in month 'mon' and year 'year'
	int Date::mdays(int mon, int year)const {
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int month = mon >= 1 && mon <= 12 ? mon : 13;
		month--;
		return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
	}

	//setting values to safe empty state
	Date::Date() {
		year = 0;
		month = 0;
		day = 0;
		error = NO_ERROR;
	}

	// checks values for valid dates
	Date::Date(int y, int m, int d) {
		if ((y >= min_year && y <= max_year) && (m >= 1 && m <= 12) && (d <= mdays(m, y))) {
			date = y * 372 + m * 31 + d;
			if (date >= min_date) {
				year = y;
				month = m;
				day = d;
				errCode(NO_ERROR);
			}
		}
		else {
			*this = Date();
			if (y < min_year || y > max_year) {
				error = YEAR_ERROR;
			}
			else if (m < 1 || m > 12) {
				error = MON_ERROR;
			}
			else if (d < 1 || d > mdays(m, y)) {
				error = DAY_ERROR;
			}
			else if (date < min_date) {
				error = PAST_ERROR;
			}
		}
	}

	// sets relevant error code
	void Date::errCode(int errorCode) {
		error = errorCode;
	}

	// returns error code
	int Date::errCode() const {
		return error;
	}

	// checks cin stream for correct format
	std::istream& Date::read(std::istream& istr) {
		int y = 0000, m = 00, d = 0;
		char c;

		errCode(NO_ERROR);

		istr >> y >> c >> m >> c >> d;
		date = y * 372 + m * 31 + d;

		if (istr.fail()) {
			errCode(CIN_FAILED);
		}
		else if (y < min_year || y > max_year) {
			errCode(YEAR_ERROR);
		}
		else if (m < 1 || m > 12) {
			errCode(MON_ERROR);
		}
		else if (d > mdays(m, y)) {
			errCode(DAY_ERROR);
		}
		else if (date < min_date) {
			errCode(PAST_ERROR);
		}
		else {
			year = y;
			month = m;
			day = d;
		}

		return istr;
	}

	// displays formatted date to screen
	std::ostream& Date::write(std::ostream& ostr) const {
		ostr << year << '/';
		if (month < 10) {
			ostr << '0';
		}
		ostr << month << '/';
		if (day < 10) {
			ostr << '0';
		}
		ostr << day;

		return ostr;
	}

	// returns true if there is an error
	bool Date::bad() const {
		return (error != NO_ERROR);
	}

	// comparison operators
	bool Date::operator==(const Date& rhs) {
		return (this->date == rhs.date);
	}

	bool Date::operator!=(const Date& rhs) {
		return (this->date != rhs.date);
	}

	bool Date::operator<(const Date& rhs) {
		return (this->date < rhs.date);
	}

	bool Date::operator<=(const Date& rhs) {
		return (this->date <= rhs.date);
	}

	bool Date::operator>(const Date& rhs) {
		return (this->date > rhs.date);
	}

	bool Date::operator>=(const Date& rhs) {
		return (this->date >= rhs.date);
	}

	//helper functions call to read and write format functions
	std::ostream& operator<<(std::ostream& ostr, const Date& dt) {
		return (dt.write(ostr));
	}

	std::istream& operator>>(std::istream& istr, Date& date) {
		return (date.read(istr));
	}
}
