// Milestone 5
// Name: Citlalli Melody Mastache
// Student #: 126275189
// Course: OOP244 Fall 2018
// File: Date.h

#ifndef AMA_DATE_H
#define AMA_DATE_H
#include <iostream>

#define NO_ERROR 0
#define CIN_FAILED 1
#define DAY_ERROR 2
#define MON_ERROR 3
#define YEAR_ERROR 4
#define PAST_ERROR 5

namespace aid {
	const int min_year = 2018, max_year = 2038, min_date = 751098;

	class Date {
		int year, month, day, error, date;

		int mdays(int, int)const;
		void errCode(int);

	public:
		Date();
		Date(int, int, int);

		bool bad() const;
		int errCode() const;
		std::istream& read(std::istream&);
		std::ostream& write(std::ostream&) const;

		bool operator==(const Date&);
		bool operator!=(const Date&);
		bool operator<(const Date&);
		bool operator<=(const Date&);
		bool operator>(const Date&);
		bool operator>=(const Date&);
	};

	std::istream& operator>>(std::istream&, Date&);
	std::ostream& operator<<(std::ostream&, const Date&);
}
#endif
