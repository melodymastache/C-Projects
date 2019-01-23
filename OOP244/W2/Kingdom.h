// OOP244 Workshop 2: Dynamic Memory
// Name: Citlalli Melody Mastache
// Student #: 126275189
// Course: OOP244 Fall 2018
// File: Kingdom.cpp

#ifndef HEADER_KINGDOM_H
#define HEADER_KINGDOM_H

namespace sict {

	struct Kingdom {
		char m_name[32];
		int m_population;
	};

	void display(Kingdom& king);

}

#endif
