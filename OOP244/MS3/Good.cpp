// Milestone 3
// Name: Citlalli Melody Mastache
// Student #: 126275189
// Course: OOP244 Fall 2018
// File: Good.cpp

#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>
#include "Good.h"
#include "Error.h"

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
		if (taxed()) {
			price = (itemPrice() * TAX) + itemPrice();
		}
		return price;
	}
	// moves error message in error object into current object
	void Good::message(const char* error) {
		return goodErr.message(error);
	}
	// returns whether or not error object is clear
	bool Good::isClear() const {
		return goodErr.isClear();
	}
	// stores received char into instance variable, then sets current object to empty state
	Good::Good(char g) {
		if (g != 'N') {
			goodType = g;
		}
		else {
			goodType = '\0';
			goodName = nullptr;
			sku_num[0] = '\0';
			unitDesc[0] = '\0';
			currentUnits = 0;
			taxable = false;
			subtotal = 0;
			neededUnits = 0;
			Error();
		}
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
			taxable = tx;
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
		fs << goodType << "," << sku() << "," << unit() << "," << name() << "," << currentUnits << "," << neededUnits << "," << itemCost() << "," << taxed();
		if (newLine) {
			fs << endl;
		}
		return fs;
	}
	// creates record for good object, loads into fstream
	std::fstream& Good::load(std::fstream& file) {
		char s[max_sku_length + 1], u[max_unit_length + 1], n[max_name_length + 1], t;
		int cu, nu;
		double sb;

		file >> t;
		file.ignore();
		file.getline(s, max_sku_length, ',');
		file.ignore();
		file.getline(u, max_unit_length, ',');
		file.ignore();
		file.getline(n, max_name_length, ',');
		file.ignore();
		file >> cu;
		file.ignore();
		file >> sb;
		file.ignore();
		file >> nu;

		Good temp(s, n, u, cu, t, sb, nu);

		*this = temp;

		return file;
	}
	// prints object data to screen
	std::ostream& Good::write(std::ostream& os, bool linear) const {
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
			os << itemCost() << "|";
			os.width(4);
			os.setf(ios::right);
			os << currentUnits << "|";
			os.unsetf(ios::right);
			os.width(10);
			os.setf(ios::left);
			os << unit() << "|";
			os.width(4);
			os.setf(ios::right);
			os << neededUnits << "|";
		}
		else {
			os << "Sku: " << sku() << "|" << endl;
			os.width(74);
			os << "Name (no spaces): " << name() << "|" << endl;
			os << "Price: " << itemPrice() << "|" << endl;
			if (taxed()) {
				os << "Price after tax: ";
				os << total_cost() << endl;
			}
			else {
				os << "N/A" << endl;
			}
			os << "Quantity on hand: " << currentUnits << ":" << endl;
			os << "Quantity needed: " << neededUnits << ":" << endl;
		}
		return os;
	}
	// accepts input for Good obj
	std::istream& Good::read(std::istream& is) {
		char sk[max_sku_length + 1], u[max_unit_length + 1], n[max_name_length + 1], t;
		int cu, nu;
		double sb;

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
		if (is.fail()) {
			is.setstate(std::ios::failbit);
			goodErr.message("Only (Y)es or (N)o are acceptable");
		}
		else {
			if (t == 'y' || t == 'Y') {
				taxable = true;
			}
			else {
				taxable = false;
			}
		}

		is.ignore(2000, '\n');
		cout << " Price: ";
		is >> sb;
		if (is.fail()) {
			goodErr.message("Invalid Price Entry");
			is.setstate(ios::failbit);
		}
		subtotal = sb;

		is.ignore(2000, '\n');
		cout << " Quantity on hand: ";
		is >> cu;
		if (is.fail()) {
			goodErr.message("Invalid Quantity Entry");
			is.setstate(ios::failbit);
		}
		currentUnits = cu;

		is.ignore(2000, '\n');
		cout << " Quantity needed: ";
		is >> nu;
		if (is.fail()) {
			goodErr.message("Invalid Quantity Needed Entry");
			is.setstate(ios::failbit);
		}
		neededUnits = nu;

		return is;
	}
	// return true if current sku is the same as passed value
	bool Good::operator==(const char * sk) const {
		if (strcmp(this->sku_num, sk) == 0) {
			return true;
		}
		return false;
	}
	// calculate cost of current units plus tax
	double Good::total_cost() const {
		return (itemCost() * currentUnits);
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
	bool Good::operator>(const Good& g) const {
		return (strcmp(this->name(), g.name()) > 0);
	}
	// operator for updating current units
	int Good::operator+=(int u) {
		if (u > 0) {
			currentUnits += u;
		}
		return currentUnits;
	}
	// operator for displaying current object
	std::ostream& operator<<(std::ostream& os, const Good& obj) {
		return obj.write(os, true);
	}
	// operator for getting input for current object
	std::istream& operator>>(std::istream& is, Good& obj) {
		return obj.read(is);
	}
	// update and return total cost of current object
	double operator+=(double& total, const Good& obj) {
		double num;
		num = total + obj.total_cost();
		return num;
	}
}
