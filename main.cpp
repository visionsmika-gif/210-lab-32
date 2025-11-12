// COMSC-210 | Lab 33 | Mika Aquino
// IDE used: Visual Studio 2022

#include "Car.h"
#include <iostream>
#include <deque>
#include <cstdlib>
#include <ctime>
#include <array>

using namespace std;

const int INITIAL_SIZE = 2;
const int NUM_LANES = 4;

// Function to print a deque of cars.
void printCars(array<deque<Car>, NUM_LANES> lanes);

int main() {
	srand(time(0));

	// Declare an array containing lanes.
	array<deque<Car>, NUM_LANES> lanes;

	// Initialize deque with 2 cars.
	cout << "Initial queue:\n";
	for (int i = 0; i < NUM_LANES; ++i) {
		cout << "Lane " << i + 1 << "\n";
		for (int j = 0; j < INITIAL_SIZE; ++j) {
			lanes[i].push_back(Car());
			cout << "\t";
			lanes[i].at(j).print();
		}
	}

	cout << "\nOutput the current deque status per the sample output\n";
	printCars(lanes);

	/*
	int time = 1;
	// Run a loop until the deque is empty.
	while (!cars.empty()) {
		cout << "\n";
		// 55% probability that the car at the head of the line pays its toll and leaves the toll booth.
		int probability = rand() % 100 + 1;
		if (probability <= 55) {
			cout << "Time: " << time << " Operation: Car paid: ";
			cars.front().print();
			cars.pop_front();
		}

		// 45% probability that another car joins the line for the doll booth.
		// The 'else' branch accounts for the chance that the probability was > 55 (accounting for the other 45 numbers out of 100)
		// NOTE: I assumed that only one operation could happen per cycle because the sample output never shows two operations happening
		// in the same cycle, so I used an if-else branch.
		else {
			cars.push_back(Car());
			cout << "Time: " << time << " Operation: Joined lane: ";
			cars.back().print();
		}

		// After each time period, display the queue.
		printCars(cars);
		++time;
	}
	*/

	return 0;
}

// Function to print an array of car lanes, where each lane is a deque of Cars.
// Args:	an array of deques of Cars
// Returns:	void
void printCars(array<deque<Car>, NUM_LANES> lanes) {
	// Loop to go through each lane
	for (int i = 0; i < NUM_LANES; ++i) {
		cout << "Lane " << i + 1 << " Queue\n";
		// If the current lane is empty, print "Empty"
		if (lanes[i].empty()) {
			cout << "\tEmpty\n";
		}
		// Else, go through the lane and print each car
		else {
			for (int j = 0; j < lanes[i].size(); ++j) {
				cout << "\t";
				lanes[i].at(j).print();
			}
		}
	}
}