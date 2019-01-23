// Workshop <Workshop #1>
// Name: <Citlalli Melody Mastache>
// Student #: <126275189>
// Course: OOP244 Winter 2018
// File: <graph.cpp>

 // namespace sict {

#include "graph.h"
#include "tools.h"
#include <iostream>
using namespace std;

namespace sict {
	// Fills the samples array with the statistic samples
	void getSamples(int samples[], int noOfSamples) {
		int i;
		for (i = 0; i < noOfSamples; i++) {
			cout << (i + 1) << "/" << noOfSamples << ": ";
			samples[i] = getInt(1, 1000000);
		}
	}

	// finds the largest sample in the samples array, if it is larger than 70,
	// otherwise it will return 70. 
	int findMax(int samples[], int noOfSamples) {
		int max = samples[0];
		int i;
		for (i = 1; i < noOfSamples; i++) {
			if (max < samples[i]) max = samples[i];
		}
		return max < 70 ? 70 : max;
	}

	// prints a scaled bar relevant to the maximum value in samples array
	void printBar(int val, int max) {
		int i;
		for (i = 0; i < 70 * val / max; i++) {
			cout << "*";
		}
		cout << " " << val << endl;
	}

	// prints a graph comparing the sample values visually 
	void printGraph(int samples[], int noOfSamples) {
		int max = findMax(samples, noOfSamples);
		cout << "Graph:" << endl;
		for (int i = 0; i < noOfSamples; i++) {
			printBar(samples[i], max);
		}
	}

}