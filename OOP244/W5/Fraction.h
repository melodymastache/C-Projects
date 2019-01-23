// Workshop 5, in lab.
// Name: Citlalli Melody Mastache
// Student #: 126275189
// Course: OOP244 Fall 2018
// File: Fraction.h

#ifndef FRACTION_H
#define FRACTION_H

namespace sict {
	class Fraction {
		int numerator, denominator;

		int max(void) const;
		int min(void) const;
		void reduce(void);
		int gcd(void) const;

	public:
		Fraction(void);
		Fraction(int, int);
		void display(void) const;
		bool isEmpty(void) const;
		Fraction operator+(const Fraction& rhs) const;
	};
}

#endif
