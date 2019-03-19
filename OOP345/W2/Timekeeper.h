/*********************************/
/* Name: Citlalli Mastache       */
/* Student Number: 126275189     */
/* Date: March 18th, 2019.       */
/* File: Timekeeper.h            */
/* Course: OOP 345               */
/* Professor: Fardad Soleimanloo */
/*********************************/

#ifndef TIMEKEEPER_H
#define TIMEKEEPER_H
#include <iostream>
#include <chrono>
#define MAX 10

namespace sict 
{
	class Timekeeper 
	{
		int currentrecs;
		std::chrono::steady_clock::time_point startTime;
		std::chrono::steady_clock::time_point endTime;

		struct Record 
		{
			const char* message;
			const char* units = " nanoseconds";
			std::chrono::steady_clock::duration duration;
		} record[MAX] {};

	public:
		Timekeeper();
		void start();
		void stop();
		void recordEvent(const char*);
		std::ostream& report(std::ostream&) const;
	};
}

#endif