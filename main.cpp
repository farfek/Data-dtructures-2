#include <iostream>
#include <cstdlib>
#include <chrono>
#include "HeapQueue.hpp"

using namespace std;
using namespace chrono;

void testInsert(int n, int prio) {

	double totalTime = 0.0;

		for (int i = 0; i < 100; i++) {

			HeapQueue<int> hq(n+1);
			for (int i = 0; i < n; i++) {

				hq.insert(i, i);

			}

			auto startTime = high_resolution_clock::now();

			hq.insert(n + 1, prio);

			auto endTime = high_resolution_clock::now();

			auto duration = duration_cast<nanoseconds>(endTime - startTime);
			totalTime += duration.count();

		}

		double averageTime = totalTime / 100;
		cout << "Sredni czas " << averageTime << endl;

}

int main() {
	
	srand(time(nullptr));

	testInsert(10, -1);
	testInsert(100, -1);
	testInsert(1000, -1);
	testInsert(10000, -1);
	testInsert(100000, -1);
	testInsert(1000000, -1);
	cout << endl;
	testInsert(10, 5);
	testInsert(100, 50);
	testInsert(1000, 500);
	testInsert(10000, 5000);
	testInsert(100000, 50000);
	testInsert(1000000, 500000);
	cout << endl;
	testInsert(10, 15);
	testInsert(100, 150);
	testInsert(1000, 1500);
	testInsert(10000, 15000);
	testInsert(100000, 150000);
	testInsert(1000000, 1500000);
	cout << endl;


}