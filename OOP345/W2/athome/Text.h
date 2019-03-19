/*********************************/
/* Name: Citlalli Mastache       */
/* Student Number: 126275189     */
/* Date: March 18th, 2019.       */
/* File: Text.h  	             */
/* Course: OOP 345               */
/* Professor: Fardad Soleimanloo */
/*********************************/

#ifndef TEXT_H
#define TEXT_H
#include <string>

namespace sict 
{
	class Text 
	{
		std::string str;
		std::string* strp = nullptr;
		size_t count;
	public:
		Text();
		Text(const std::string&);
		//copy functions
		Text(const Text&);
		Text& operator=(const Text&);
		//move functions
		Text(const Text&&);
		Text& operator=(Text&&);
		~Text();
		size_t size() const;
	};
}

#endif 
