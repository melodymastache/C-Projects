/******************************/
/* Author: Citlalli Mastache  */
/* Date: February 13, 2019.   */
/* Student ID: 126275189	  */
/* File: Message.cpp		  */
/******************************/

#include <iostream>
#include <string>
#include "Message.h"

namespace sict
{
	/* constructor setting members to safe empty state */
	Message::Message() 
	{
		user[0] = '\0';
		reply[0] = '\0';
		message[0] = '\0';
	}
	Message::Message(const std::string& str)
	{
		std::string::size_type pos = str.find(' ');
		user = str.substr(0, pos);
		std::string buffer = str.substr(pos + 1, str.length());
		if (user.size() > 0 && user.size() != str.size())
		{
			if (buffer.find('@') != std::string::npos)
			{
				pos = buffer.find(' ');
				reply = buffer.substr(1, pos - 1);
				message = buffer.substr(pos + 1, buffer.length());
			}
			else
			{
				message = buffer.substr(0, buffer.length());
			}
		}
		else
		{
			*this = Message();
		}
	}
	bool Message::empty() const
	{
		return ((user[0] == '\0' || reply[0] == '\0') && message[0] == '\0');
	}
	void Message::display(std::ostream& os) const
	{
		if (!empty())
		{
			os << ">User  : " << user << std::endl;
			if (reply.size() > 0)
			{
				os << " Reply : " << reply << std::endl;
			}
			os << " Tweet : " << message << std::endl;
		}
	}
}
