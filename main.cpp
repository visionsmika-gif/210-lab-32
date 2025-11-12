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
void printCars(const deque<Car> cars);

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

	for (int i = 0; i < NUM_LANES; ++i) {

		for (int j = 0; j < lanes[i].size(); ++i) {
			lanes[i].at(j).print();
			cout << 
		}
	}


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

// Function to print a deque of cars.
// Args:	deque of Car objects
// Returns:	void
void printCars(const deque<Car> cars) {
	cout << "Queue:\n";
	if (cars.empty()) {
		cout << "\tEmpty\n";
		return;
	}
	for (Car car : cars) {
		cout << "\t";
		car.print();
	}
}