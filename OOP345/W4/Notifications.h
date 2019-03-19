/******************************/
/* Author: Citlalli Mastache  */
/* Date: February 14, 2019.   */
/* Student ID: 126275189	  */
/* File: Notifications.h	  */
/******************************/

#ifndef SICT_NOTIFICATIONS_H
#define SICT_NOTIFICATIONS_H
#include "Message.h"

namespace sict
{
	class Notifications
	{
		const Message** mess;
		int max;
		int current;

	public:
		/* constructor */
		Notifications();

		/* destructor */
		~Notifications();

		/* allocates dynamic memory */
		Notifications(int);

		/* copy constructor */
		Notifications(const Notifications&);

		/* copy assignment operator */
		Notifications& operator=(const Notifications&);

		/* move constructor */
		Notifications(Notifications&&);

		/* move assignment operator */
		Notifications& operator=(Notifications&&);

		/* array update function */
		Notifications& operator+=(const Message&);

		/* array removal function */
		Notifications& operator-=(const Message&);

		/* display ostream function */
		void display(std::ostream&) const;

		/* return current size of array */
		size_t size() const;
	};
	/* helper ostream operator */
	std::ostream& operator<<(std::ostream&, const Notifications&);
}

#endif