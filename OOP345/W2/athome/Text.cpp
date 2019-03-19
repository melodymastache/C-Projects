/*********************************/
/* Name: Citlalli Mastache       */
/* Student Number: 126275189     */
/* Date: March 18th, 2019.       */
/* File: Text.cpp	             */
/* Course: OOP 345               */
/* Professor: Fardad Soleimanloo */
/*********************************/

#include <iostream>
#include <string>
#include <fstream>
#include "Text.h"

using namespace std;

namespace sict
{
	// default constructor
	Text::Text()
	{
		str = '\0';
		strp = nullptr;
		count = 0;
	}
	// 1 arg constructor: opens file passed through parameters, counts the number of records, copies the records into the object.
	Text::Text(const string& fname)
	{
		ifstream file(fname);
		string buff;
		if (!file.fail())
		{
			int i;
			char c;
			while (!file.eof())
			{
				c = file.get();
				if (c == '\n') {
					count++; // counting how many records are in the file
				}
			}
			file.clear();
			strp = new string[count];
			file.seekg(ios::beg);
			for (i = 0; i < count; i++)
			{
				getline(file, strp[i], '\n');
			}
			file.close();
		}
	}
	//copy constructor
	Text::Text(const Text& obj)
	{
		operator=(obj);
	}
	// copy assignment operator
	Text& Text::operator=(const Text& obj)
	{
		if (this != &obj)
		{
			count = obj.count;
			delete[] strp;
			strp = new string[count];
			for (int i = 0; i < count; i++)
			{
				strp[i] = obj.strp[i];
			}
		}
		return *this;
	}
	// move constructor
	Text::Text(const Text&& obj) 
	{
		*this = move(obj);
		//operator=(obj); ???
	}
	// move assignment operator
	Text& Text::operator=(Text&& obj)
	{
		//check for self-assignment
		if (this != &obj)
		{
			delete[] strp;
			strp = obj.strp;
			count = obj.count;
			str = obj.str;
			obj.strp = nullptr;
			obj.str = '\0';
			obj.count = 0;
		}
		return *this;
	}
	// destructor
	Text::~Text()
	{
		delete[] strp;
	}
	// returns number of records
	size_t Text::size() const
	{
		return count;
	}
}