/******************************/
/* Author: Citlalli Mastache  */
/* Date: February 13, 2019.   */
/* Student ID: 126275189	  */
/* File: Message.h			  */
/******************************/

#ifndef SICT_MESSAGE_H
#define SICT_MESSAGE_H
#include <string>

namespace sict {
	class Message {
		std::string user;
		std::string reply;
		std::string message;
	public:
		Message();
		Message(const std::string&);
		bool empty() const;
		void display(std::ostream&) const;
	};
}

#endif
