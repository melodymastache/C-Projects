// Workshop 5, in lab.
// Name: Citlalli Melody Mastache
// Student #: 126275189
// Course: OOP244 Fall 2018
// File: Fraction.cpp

#include <iostream>
#include "Fraction.h"
using namespace std;

namespace sict {

	Fraction::Fraction(void) {
		numerator = 0;
		denominator = 0;
	}

	Fraction::Fraction(int num, int denom) {
		if (num > 0 && denom > 0) {
			numerator = num;
			denominator = denom;
			reduce();			
		}
		else {
			*this = Fraction();
		}

	}

	int Fraction::max(void) const {
		return (numerator >= denominator) ? numerator : denominator;
	}

	int Fraction::min(void) const {
		return (numerator <= denominator) ? numerator : denominator;
	}

	// gcd returns the greatest common divisor of num and denom
	//
	int Fraction::gcd() const {
		int mn = min();  // min of numerator and denominator
		int mx = max();  // max of numerator and denominator
		int g_c_d = 1;
		bool found = false;

		for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
			if (mx % x == 0 && mn % x == 0) {
				found = true;
				g_c_d = x;
			}
		}
		return g_c_d;
	}

	void Fraction::reduce() {
		int frac = gcd();

		numerator /= frac;
		denominator /= frac;
	}

	void Fraction::display(void) const{

		bool invalid = isEmpty();

		if (invalid) {
			cout << "no fraction stored";
		}
		else if (denominator == 1) {
			cout << numerator;
		}
		else {
			cout << numerator << "/" << denominator;
		}
	}

	bool Fraction::isEmpty(void) const {
		return (numerator == 0 && denominator == 0);
	}

	Fraction Fraction::operator+(const Fraction& rhs) const {
		Fraction copy;
		int num, denom;
		
		if (!isEmpty() && !rhs.isEmpty()) {
			denom = denominator * rhs.denominator;
			num = (numerator * rhs.denominator) + (rhs.numerator * denominator);
			copy = Fraction(num, denom);
		}
		else {
			copy = Fraction();
		}
		
		copy.reduce();
		return copy;
	}
}
