/******************************/
/* Author: Citlalli Mastache  */
/* Date: February 14, 2019.   */
/* Student ID: 126275189	  */
/* File: MessagePack.cpp	  */
/******************************/

#include <iostream>
#include "MessagePack.h"
#include "Message.h"

namespace sict
{
	/* setting object to safe empty state */
	MessagePack::MessagePack()
	{
		messages = nullptr;
		count = 0;
	}
	
	/* deallocating memory for pointers */
	MessagePack::~MessagePack()
	{
		messages = nullptr;
		delete[] messages;
	}

	/* copy constructor */
	MessagePack::MessagePack(const MessagePack& obj)
	{
		*this = obj;
	}

	/* copy assignment operator */
	MessagePack& MessagePack::operator=(const MessagePack& obj)
	{
		if (this != &obj)
		{
			for (int i = 0; i < count; i++)
			{
				messages[i] = obj.messages[i];
			}
			count = obj.count;
		}
		else
		{
			*this = MessagePack();
		}
		return *this;
	}

	/* move constructor */
	MessagePack::MessagePack(MessagePack&& obj)
	{
		*this = std::move(obj);
	}

	/* move assignment operator */
	MessagePack& MessagePack::operator=(MessagePack&& obj)
	{
		if (this != &obj)
		{
			messages = std::move(obj.messages);
			count = std::move(obj.count);
		}
		else
		{
			*this = MessagePack();
		}
		return *this;
	}

	/* stores new array members */
	MessagePack::MessagePack(Message** obj, size_t cnt)
	{
		if (cnt > 0 && obj != nullptr)
		{
			messages = new Message[cnt];
			for (int i = 0; i < cnt; i++)
			{
				if (!(*obj[i]).empty())
				{
					messages[i] = *obj[i];
				}
				else
				{
					messages[i] = Message();
				}
				count++;
			}
		}
		else
		{
			*this = MessagePack();
		}
	}

	/* display ostream to screen */
	void MessagePack::display(std::ostream& os) const
	{
		for (int i = 0; i < count; i++)
		{
			if (!messages[i].empty())
			{
				messages[i].display(os);
			}
		}
	}

	/* return current array size */
	size_t MessagePack::size() const
	{
		return count;
	}

	/* inserting object to ostream */
	std::ostream& operator<<(std::ostream& os, const MessagePack& obj)
	{
		obj.display(os);
		return os;
	}
}
