#include "Car.h"
#include <iostream>
#include <deque>
#include <cstdlib>
#include <ctime>

using namespace std;

const int INITIAL_SIZE = 2;

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

int main() {
	srand(time(0));

	// Declare a deque of cars.
	deque<Car> cars;

	// Initialize deque with 2 cars.
	cout << "Initial queue:\n";
	for (int i = 0; i < INITIAL_SIZE; ++i) {
		cars.push_back(Car());
		cout << "\t";
		cars.at(i).print();
	}

	int time = 1;
	// Run a loop until the deque is empty.
	while (!cars.empty()) {
		bool somethingHappened = false;

		// 55% probability that the car at the head of the line pays its toll and leaves the toll booth
		int probability = rand() % 100 + 1;
		if (probability <= 55) {
			cout << "Time: " << time << " Operation: Car paid: ";
			cars.front().print();
			cars.pop_front();
			somethingHappened = true;
		}

		// 45% probability that another car joins the line for the doll booth
		probability = rand() % 100 + 1;
		if (probability <= 45) {
			cars.push_back(Car());
			cout << "Time: " << time << " Operation: Joined lane: ";
			cars.back().print();
			somethingHappened = true;
		}

		// After each time period, display the queue
		printCars(cars);
		++time;
	}

	return 0;
}