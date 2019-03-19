/*********************************/
/* Name: Citlalli Mastache       */
/* Student Number: 126275189     */
/* Date: March 18th, 2019.       */
/* File: Timekeeper.cpp          */
/* Course: OOP 345               */
/* Professor: Fardad Soleimanloo */
/*********************************/

#include <iostream>
#include <chrono>
#include <iomanip>
#include "Timekeeper.h"
#include "Text.h"

using namespace std;

namespace sict 
{
	// default constructor
	Timekeeper::Timekeeper()
	{
		currentrecs = 0;
	}
	// start timer
	void Timekeeper::start()
	{
		startTime = chrono::steady_clock::now();
	}
	// stop timer
	void Timekeeper::stop()
	{
		endTime = chrono::steady_clock::now();
	}
	// calculating duration of event, recording to object
	void Timekeeper::recordEvent(const char* event) 
	{
		if (currentrecs < MAX)
		{
			record[currentrecs].message = event;
			record[currentrecs].duration = chrono::duration_cast<chrono::milliseconds>(endTime - startTime);
			currentrecs++;
		}
	}
	// send object data to screen display 
	ostream& Timekeeper::report(ostream& os) const
	{
		os << "\nExecution Times:\n";
		int i = 0;
			for (i = 0; i < currentrecs; i++) 
			{
				os << record[i].message << setw(6) << record[i].duration.count()/1000000 << " " << record[i].units << endl;
			}
		return os;
	}
}