// Milestone 3
// Name: Citlalli Melody Mastache
// Student #: 126275189
// Course: OOP244 Fall 2018
// File: Error.h

#ifndef AID_ERROR_H
#define AID_ERROR_H
#include <iostream>

namespace aid {
	class Error {
		char * errorMessage;

	public:
		explicit Error(const char* error = nullptr);
		Error(const Error& em) = delete;
		Error& operator=(const Error& em) = delete;
		virtual ~Error();
		void clear();
		bool isClear() const;
		void message(const char*);
		const char* message() const;
	};
	std::ostream& operator<<(std::ostream&, const Error&);
}
#endif
