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
const int NUM_SIMS = 20;

const int PROB_PAY = 46;
const int PROB_JOIN = 39;
const int PROB_SHIFT = 15;

// Function to print a deque of cars.
void printCars(array<deque<Car>, NUM_LANES> lanes);

int main() {
	srand(time(0));

	// Declare an array containing lanes.
	array<deque<Car>, NUM_LANES> lanes;

	// Initialize the lanes with cars.
	cout << "Initial queue:\n";
	for (int i = 0; i < NUM_LANES; ++i) {
		cout << "Lane " << i + 1 << ":\n";
		for (int j = 0; j < INITIAL_SIZE; ++j) {
			lanes[i].push_back(Car());
			cout << "\t";
			lanes[i].at(j).print();
		}
	}

	// Run the simulation a number of times.
	for (int time = 0; time < NUM_SIMS; ++time) {
		cout << "\nTime: " << time + 1 << "\n";

		for (int i = 0; i < NUM_LANES; ++i) {

			// TODO: If a lane is currently empty but there is still more time in the simulation, those probabilities will be just 50/50 if a new car enters the queue or not. 


			// 46% probability that the car at the head of the queue pays its toll and leaves the queue.
			int probability = rand() % 100 + 1;
			if (probability <= PROB_PAY && !lanes[i].empty()) {
				cout << "Lane " << i + 1 << " Paid: ";
				lanes[i].front().print();
				lanes[i].pop_front();
			}
			// 39% probability that another car joins the queue.
			else if (probability <= PROB_PAY + PROB_JOIN) {
				lanes[i].push_back(Car());
				cout << "Lane " << i + 1 << " Joined: ";
				lanes[i].back().print();
			}
			// 15% probability that the rear car will shift lanes.
			else if (!lanes[i].empty()) {
				// Remove car from current lane.
				Car shiftingCar = lanes[i].back();
				lanes[i].pop_back();

				// Print action.
				cout << "Lane " << i + 1 << " Switched: ";
				shiftingCar.print();

				// Choose a new lane to enter.
				int newLane;
				do {
					newLane = rand() % NUM_LANES;
				} while (newLane == i);	// Ensure that the new lane does not equal the current lane.

				// Add the shifting car to the new lane.
				lanes[newLane].push_back(shiftingCar);
			}
		}

		// After each time period, print the resulting lanes
		printCars(lanes);
	}

	return 0;
}

// Function to print an array of car lanes, where each lane is a deque of Cars.
// Args:	an array of deques of Cars
// Returns:	void
void printCars(array<deque<Car>, NUM_LANES> lanes) {
	// Loop to go through each lane
	for (int i = 0; i < NUM_LANES; ++i) {
		cout << "Lane " << i + 1 << " Queue:\n";
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