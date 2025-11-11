#include "Car.h"
#include <iostream>
#include <deque>
#include <cstdlib>
#include <ctime>

using namespace std;

const int INITIAL_SIZE = 2;

int main() {
	srand(time(0));

	// Declare a deque of cars
	deque<Car> cars;

	// Initialize deque with 2 cars
	cout << "Initial queue:\n";
	for (int i = 0; i < INITIAL_SIZE; ++i) {
		cars.push_back(Car());
		cout << "\t";
		cars.at(i).print();
	}


	return 0;
}