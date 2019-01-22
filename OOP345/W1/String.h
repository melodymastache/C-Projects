/******************************/
/* Name: Citlalli Mastache    */
/* Student Number: 126275189  */
/* Date: January 21st, 2019.  */
/* File: String.h             */
/* Course: OOP 345            */
/* Professor: Asam Gulaid     */
/******************************/

#ifndef STRING_H
#define STRING_H

namespace sict {
	class String {
		char* str;

	public: 
		String(const char*);
		void display(std::ostream&) const;
		bool empty() const;
	};
	const int INITIAL = 3;
	std::ostream& operator<<(std::ostream& os, const String& obj);
}

#endif
