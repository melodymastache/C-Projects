/******************************/
/* Author: Citlalli Mastache  */
/* Date: February 13, 2019.   */
/* Student ID: 126275189	  */
/* File: MessagePack.h		  */
/******************************/

#ifndef SICT_MESSAGEPACK_H
#define SICT_MESSAGEPACK_H
#include <iostream>
#include "Message.h"
	
namespace sict
{
	class MessagePack
	{
		size_t count;
		Message* messages;

	public:
		/* constructor */
		MessagePack();

		/* destructor */
		~MessagePack(); 

		/* two parameter constructor */
		MessagePack(Message**, size_t);

		/* copy constructor */
		MessagePack(const MessagePack&);

		/* copy assignment operator */
		MessagePack& operator=(const MessagePack&);

		/* move constructor */
		MessagePack(MessagePack&&); 

		/* move assignment operator */
		MessagePack& operator=(MessagePack&&);

		/* displays ostream to screen */
		void display(std::ostream&) const;

		/* returns current size of array */
		size_t size() const;
	};
	/* ostream helper operator */
	std::ostream& operator<<(std::ostream&, const MessagePack&);
}

#endif
