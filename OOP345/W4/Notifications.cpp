/******************************/
/* Author: Citlalli Mastache  */
/* Date: February 14, 2019.   */
/* Student ID: 126275189	  */
/* File: Notifications.cpp	  */
/******************************/

#include <iostream>
#include <array>
#include "Notifications.h"

namespace sict
{
	// default constructor sets members to safe empty state
	Notifications::Notifications()
	{
		mess = nullptr;
		max = 0;
		current = 0;
	}

	//destructor for pointers
	Notifications::~Notifications()
	{
		mess = nullptr;
		delete mess;
	}

	// copy constructor
	Notifications::Notifications(const Notifications& obj)
	{
		*this = obj;
	}

	//copy assignment operator
	Notifications& Notifications::operator=(const Notifications& obj)
	{
		if (this != &obj)
		{
			max = obj.max;
			current = obj.current;
			for (int i = 0; i < obj.current; i++)
			{
				mess[i] = obj.mess[i];
			}
			mess[current] = '\0';
		}
		else
		{
			*this = Notifications();
		}
		return *this;
	}

	//move constructor
	Notifications::Notifications(Notifications&& obj)
	{
		*this = std::move(obj);
	}

	//move assignment operator
	Notifications& Notifications::operator=(Notifications&& obj)
	{
		if (this != &obj)
		{
			mess = std::move(obj.mess);
			current = std::move(obj.current);
			max = std::move(obj.max);
		}
		else
		{
			*this = Notifications();
		}
		return *this;
	}

	// allocates memory for pointers to message objects
	Notifications::Notifications(int cnt)
	{
		if (cnt > 0)
		{
			mess = new const Message*[cnt];
			max = cnt;
		}
		else
		{
			*this = Notifications();
		}
	}

	/* adding new object to array */
	Notifications& Notifications::operator+=(const Message& obj)
	{
		if (!obj.empty() && (current < max))
		{
			mess[current] = &obj;
			current++;
		}
		return *this;
	}

	/* removing object from array */ 
	Notifications& Notifications::operator-=(const Message& obj)
	{
		for (int i = 0; i < current; i++)
		{
			if (mess[i] == &obj)
			{
				mess[i] = nullptr;
				// shifting the array to bring empty space to end
				for (int in = i; in < current - 1; in++)
				{
					mess[in] = mess[in + 1];
				}
				mess[current - 1] = nullptr;
			}
		}
		current--;
		return *this;
	}

	/* formats ostream */
	void Notifications::display(std::ostream& os) const
	{
		for (int i = 0; i < current; i++)
		{
			os << mess[i];
		}
	}

	// returns "current" variable
	size_t Notifications::size() const
	{
		return current;
	}

	// displays ostream to screen
	std::ostream & operator<<(std::ostream& os, const Notifications& obj)
	{
		obj.display(os);
		return os;
	}

}