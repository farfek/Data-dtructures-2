#include <iostream>

using namespace std;

template<typename T>
class Element {

private:

	int priority;
	T value;


public:

	Element(T val, int prio): value(val), priority(prio) {}
	Element() {}
	~Element() {}

	int getPriority() {

		return priority;

	}

	T getValue() {

		return value;

	}

	void insertPriority(int newPriority) {

		priority = newPriority;

	}

};