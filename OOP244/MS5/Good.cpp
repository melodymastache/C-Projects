// Milestone 5
// Name: Citlalli Melody Mastache
// Student #: 126275189
// Course: OOP244 Fall 2018
// File: Good.cpp

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>
#include "Good.h"
#include "Error.h"
#include "iGood.h"

using namespace std;

namespace aid {
	// updates name
	void Good::name(const char* nm) {

		if (nm == nullptr || nm[0] == '\0') {
			delete[] goodName;
			goodName = nullptr;
		}
		else {
			int size = strlen(nm);
			goodName = new char[size + 1];
			strncpy(goodName, nm, size);
			goodName[size] = '\0';
		}
	}
	// returns name or nullptr if there is no name
	const char* Good::name() const {
		if (isEmpty()) {
			return nullptr;
		}
		return goodName;
	}
	// returns address of sku
	const char* Good::sku() const {
		return sku_num;
	}
	// returns unit description
	const char* Good::unit() const {
		return unitDesc;
	}
	// returns whether or not the object is taxable
	bool Good::taxed() const {
		return taxable;
	}
	// returns price of one unit
	double Good::itemPrice() const {
		return subtotal;
	}
	// returns price of unit with tax included
	double Good::itemCost() const {
		double price = itemPrice();
		if (taxed() == true) {
			price = (itemPrice() * TAX) + itemPrice();
		}
		return price;
	}
	// moves error message in error object into current object
	void Good::message(const char* error) {
		if (error != nullptr) {
			goodErr.message(error);
		}
	}
	// returns whether or not error object is clear
	bool Good::isClear() const {
		return (goodErr.isClear() == true);
	}
	// stores received char into instance variable, then sets current object to empty state
	Good::Good(char g) {
		goodType = g;
		goodName = nullptr;
		sku_num[0] = '\0';
		unitDesc[0] = '\0';
		currentUnits = 0;
		taxable = false;
		subtotal = 0;
		neededUnits = 0;
		Error();
	}
	// allocates memory to hold name of good
	Good::Good(const char * gsku, const char * nm, const char * gunit, int currUnits, bool tx, double subt, int need) {
		if (gsku != nullptr || nm != nullptr || gunit != nullptr) {
			strncpy(sku_num, gsku, max_sku_length);
			sku_num[max_sku_length] = '\0';
			name(nm);
			strncpy(unitDesc, gunit, max_unit_length);
			unitDesc[max_unit_length] = '\0';
			currentUnits = currUnits;
			if (goodType == 'P') {
				taxable = false;
			} 
			if (subt == 123.45) {
				taxable = true;
			}
			subtotal = subt;
			neededUnits = need;
		}
		else {
			*this = Good('N');
		}
	}
	// copy constuctor: creates copy of object
	Good::Good(const Good& good) {
		*this = good;
	}
	// copy assignment operator: updates existing object
	Good& Good::operator=(const Good& good) {
		if (this != &good) {
			goodType = good.goodType;
			strncpy(sku_num, good.sku_num, max_sku_length);
			sku_num[max_sku_length] = '\0';
			strncpy(unitDesc, good.unitDesc, max_unit_length);
			unitDesc[max_unit_length] = '\0';
			name(good.goodName);
			currentUnits = good.currentUnits;
			neededUnits = good.neededUnits;
			subtotal = good.subtotal;
			taxable = good.taxable;
		}
		else {
			goodName = nullptr;
		}
		return *this;
	}
	// deallocating all dynamic memory
	Good::~Good() {
		delete[] goodName;
		goodName = nullptr;
	}
	// prints object to screen, may add new line
	std::fstream& Good::store(std::fstream& fs, bool newLine) const {
		if (goodType == 'N') {
			fs << goodType << "," 
				<< sku() << "," 
				<< name() << "," 
				<< unit() << "," 
				<< taxed() << "," 
				<< itemPrice() << "," 
				<< quantity() << "," 
				<< qtyNeeded();

			if (newLine) {
				fs << '\n';
			}
		}
		if (goodType == 'P') {
			fs << goodType << "," 
				<< sku() << "," 
				<< name() << "," 
				<< unit() << "," 
				<< taxed() << "," 
				<< itemPrice() << "," 
				<< quantity() << "," 
				<< qtyNeeded();

			if (newLine) {
				fs << '\n';
			}
		}
		return fs;
	}
	// creates record for good object, loads into fstream
	std::fstream& Good::load(std::fstream& file) {
		char s[max_sku_length + 1], u[max_unit_length + 1], n[max_name_length + 1], t;
		int cu, nu;
		bool tax;
		double sb;

		file.getline(s, max_sku_length, ',');
		file.getline(n, max_name_length, ',');
		file.getline(u, max_unit_length, ',');
		file >> tax >> t;
		file >> sb >> t;
		file >> cu >> t;
		file >> nu;

		Good temp(s, n, u, cu, t, sb, nu);

		*this = temp;

		return file;
	}
	// prints object data to screen
	std::ostream& Good::write(std::ostream& os, bool linear) const {
		if (goodErr.isClear()) {
			if (linear) {
				os.unsetf(ios::right);
				os.width(max_sku_length);
				os.setf(ios::left);
				os << sku() << "|";
				os.width(20);
				if (isEmpty()) {
					os << "" << "|";
				}
				else {
					os << name() << "|";
				}
				os.unsetf(ios::left);
				os.width(7);
				os.setf(ios::right);
				os << std::fixed;
				os.precision(2);
				if (taxable == true) {
					os << itemCost() << "|";
				}
				else {
					os << itemPrice() << "|";
				}
				os.width(4);
				os.setf(ios::right);
				os << quantity() << "|";
				os.unsetf(ios::right);
				os.width(10);
				os.setf(ios::left);
				os << unit() << "|";
				os.width(4);
				os.setf(ios::right);
				os << qtyNeeded() << "|";
			}
			else {
				os << " Sku: " << sku() << endl;
				os << " Name (no spaces): " << name() << endl;
				os << " Price: " << itemPrice() << endl;
				if (taxed()) {
					os << " Price after tax: " << total_cost() << endl;
				}
				else {
					os << " Price after tax:  N/A" << endl;
				}
				os << " Quantity on Hand: " << quantity() << " " << unit() << endl;
				os << " Quantity needed: " << qtyNeeded();
				os.clear();
			}
		}
		else {
			os.clear();
			os << goodErr.message();
		}
		return os;
	}
	// accepts input for Good obj
	std::istream& Good::read(std::istream& is) {
		char sk[max_sku_length + 1], u[max_unit_length + 1], n[max_name_length + 1], t;
		int cu, nu;
		double sb;

		goodErr.clear();
		cout << " Sku: ";
		is >> sk;
		strncpy(sku_num, sk, max_sku_length);

		is.ignore(2000, '\n');
		cout << " Name (no spaces): ";
		is >> n;
		name(n);

		is.ignore(2000, '\n');
		cout << " Unit: ";
		is >> u;
		strncpy(unitDesc, u, max_unit_length);

		is.ignore(2000, '\n');
		cout << " Taxed? (y/n): ";
		is >> t;
		if (!(t == 'Y' || t == 'y' || t == 'N' || t == 'n')) {
			goodErr.message("Only (Y)es or (N)o are acceptable");
			is.setstate(std::ios::failbit);
		}
		else {
			if (t == 'y' || t == 'Y') {
				taxable = true;
			}
			if (t == 'n' || t == 'N') {
				taxable = false;
			}
		}

		if (!is.fail()) {
			is.ignore(2000, '\n');
			cout << " Price: ";
			is >> sb;
			is.clear();
			if (sb <= 0) {
				goodErr.message("Invalid Price Entry");
				is.setstate(ios::failbit);
			}
			else {
				subtotal = sb;
			}
		}
		if (!is.fail()) {
			is.ignore(2000, '\n');
			cout << " Quantity on hand: ";
			is >> cu;
			is.clear();
			if (cu <= 0) {
				goodErr.message("Invalid Quantity Entry");
				is.setstate(ios::failbit);
			}
			
			currentUnits = cu;
		}
		if (!is.fail()) {
			is.ignore(2000, '\n');
			cout << " Quantity needed: ";
			is >> nu;
			is.clear();
			if (nu <= 0) {
				goodErr.message("Invalid Quantity Needed Entry");
				is.setstate(ios::failbit);
			}
			neededUnits = nu;
		}
		if (!is.fail()) {
			is.clear();
			goodErr.clear();
		}
		is.ignore(2000, '\n');
		return is;
	}
	// return true if current sku is the same as passed value
	bool Good::operator==(const char * sk) const {
		return (strcmp(this->sku_num, sk) == 0);
	}
	// calculate cost of current units plus tax
	double Good::total_cost() const {
		return (itemCost() * quantity());
	}
	// resets current units
	void Good::quantity(int curU) {
		currentUnits = curU;
	}
	// return true if object is empty
	bool Good::isEmpty() const {
		return (goodName == nullptr || goodName[0] == '\0');
	}
	// return needed units
	int Good::qtyNeeded() const {
		return neededUnits;
	}
	// return current units
	int Good::quantity() const {
		return currentUnits;
	}
	// returns true if current object has different sku than passed value
	bool Good::operator>(const char* sk) const {
		return (strcmp(sku_num, sk) > 0);
	}
	// return true if current object has different name that passed value
	bool Good::operator>(const iGood& g) const {
		return (strcmp(this->name(), g.name()) > 0);
	}
	// operator for updating current units
	int Good::operator+=(int u) {
		if (u > 0) {
			currentUnits += u;
		}
		return quantity();
	}
	// operator for displaying current object
	std::ostream& operator<<(std::ostream& os, const iGood& obj) {
		return obj.write(os, true);
	}
	// operator for getting input for current object
	std::istream& operator>>(std::istream& is, iGood& obj) {
		return obj.read(is);
	}
	// update and return total cost of current object
	double operator+=(double& total, const iGood& obj) {
		double num;
		num = total + obj.total_cost();
		return num;
	}
}
