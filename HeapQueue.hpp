#include <iostream>
#include <stdexcept>
#include "Element.hpp"

using namespace std;

template <typename T>
class HeapQueue {

private:

	Element<T>* element;
	int capacity;
	int size;

	void heapifyup(int index) {

		while (index != 0) {

			int parent_index = (index - 1) / 2;

			if (element[index].getPriority() > element[parent_index].getPriority()) {

				swap(element[index], element[parent_index]);
				index = parent_index;

			}
			else break;

		}

	}

	void heapifydown(int index) {

		while (index != size - 1) {

			int leftChild = index * 2 + 1;
			int rightChild = index * 2 + 2;
			int biggerChild;

			if (rightChild > size - 1 || leftChild > size - 1) break;

			if (element[leftChild].getPriority() > element[rightChild].getPriority()) {

				biggerChild = leftChild;

			}
			else biggerChild = rightChild;

			if (element[biggerChild].getPriority() > element[index].getPriority()) {

				swap(element[biggerChild], element[index]);
				index = biggerChild;

			}
			else break;

		}
		

	}

	void resize() {

		int newCapacity = 2 * capacity;
		Element<T>* newElement = new Element<T>[newCapacity];

		for (int i = 0;i < capacity; i++) {

			newElement[i] = element[i];

		}

		delete[] element;
		element = newElement;
		capacity = newCapacity;

	}

public:

	HeapQueue(int cap): capacity(cap), size(0){
	
		element = new Element<T>[capacity];

	}

	~HeapQueue(){
		
		delete[] element;

	}

	void insert(T value, int priority) {

		if (size == capacity) resize();

		element[size++] = Element<T>(value, priority);
		
		heapifyup(size - 1);

	}

	T removeMax() {

		if (size == 0) throw logic_error("Queue is empty");

		T maxValue = element[0].getValue();
		swap(element[0], element[--size]);
		heapifydown(0);

		return maxValue;

	}

	int returnSize() {

		return size;

	}

	T peek() {

		if (size == 0) throw logic_error("Queue is empty");

		return element[0].getValue();

	}

	void modifyPriority(T searchValue, int newPriority) {

		int index;

		for (int i = 0;i < size; i++) {

			if (element[i].getValue() == searchValue) {

				element[i].insertPriority(newPriority);
				index = i;
				break;

			}

		}

		heapifyup(index);
		heapifydown(index);

	}

	void display() {

		cout << "Current capacity is " << capacity << endl;
		cout << "Current size is " << size << endl << endl << endl;

		for (int i = 0; i < size; i++) {

			cout << "Index of element " << i << endl;
			cout << "Priority of element " << element[i].getPriority() << endl;;
			cout << "Value of element " << element[i].getValue() << endl << endl;

		}

	}

};