// Milestone 5
// Name: Citlalli Melody Mastache
// Student #: 126275189
// Course: OOP244 Fall 2018
// File: Good.h

#ifndef AID_GOOD_H
#define AID_GOOD_H
#include <iostream>
#include "Error.h"
#include "iGood.h"

namespace aid {
	const int max_sku_length = 7;
	const int max_unit_length = 10;
	const int max_name_length = 75;
	const double TAX = 0.13;

	class Good : public iGood {
		char goodType = 'P';
		char sku_num[max_sku_length + 1];
		char unitDesc[max_unit_length + 1];
		char * goodName = nullptr;
		int currentUnits;
		int neededUnits;
		double subtotal;
		bool taxable;
		Error goodErr;

	protected:
		void name(const char*);
		const char* name() const;
		const char* sku() const;
		const char* unit() const;
		bool taxed() const;
		double itemPrice() const;
		double itemCost() const;
		void message(const char*);
		bool isClear() const;

	public:
		Good(char goodType = 'N');
		Good(const char *, const char *, const char *, int currentUnits = 0, bool taxable = true, double subtotal = 0, int neededUnits = 0);
		Good(const Good&);
		Good& operator=(const Good&);
		~Good();
		std::fstream& store(std::fstream&, bool newLine = true) const;
		std::fstream& load(std::fstream&);
		std::ostream& write(std::ostream&, bool) const;
		std::istream& read(std::istream&);
		bool operator==(const char*) const;
		double total_cost() const;
		void quantity(int);
		bool isEmpty() const;
		int qtyNeeded() const;
		int quantity() const;
		bool operator>(const char*) const;
		bool operator>(const iGood&) const;
		int operator+=(int);
	};
	std::ostream& operator<<(std::ostream&, const iGood&);
	std::istream& operator>>(std::istream&, iGood&);
	double operator+=(double&, const iGood&);

	iGood* CreateGood();
}
#endif
