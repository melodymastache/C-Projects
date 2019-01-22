/******************************/
/* Name: Citlalli Mastache    */
/* Student Number: 126275189  */
/* Date: January 17th, 2019.  */
/* File: w1.cpp               */
/* Course: OOP 345            */
/* Professor: Asam Gulaid     */
/******************************/

#include <iostream>
#include "process.h"
#include "String.h"
#define MAX 3
using namespace sict;
extern const int INITIAL = MAX;


int main(int num, char* args[]) {
	if (num == 0) {
		std::cout << "***Insufficient number of arguments***" << std::endl;
		return 1;
	}
	else {
		std::cout << "Command Line : ";
		for (int i = 0; i < num; i++) {
			std::cout << args[i] << " ";
		}
		std::cout << std::endl;
	}
	for (int i = 1; i < num; i++) {
		process(args[i]);
	}
	return 0;
}
