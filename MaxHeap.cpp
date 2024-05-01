#include <iostream>
#include <stdexcept>
#include "Element.hpp"
using namespace std;

template <typename T, typename P>
class PriorityQueue {

private:

    Element<T, P>* heap;
    size_t capacity;
    size_t currentSize;

    //Przywracanie w³aœciwoœci kopca Maxheap do góry
    void heapifyUp() {

        int index = currentSize - 1;
        while (index > 0) {

            int parentIndex = (index - 1) / 2;

            if (heap[parentIndex].priority < heap[index].priority) {

                std::swap(heap[parentIndex], heap[index]);
                index = parentIndex;

            }
            else break;

        }
    }

    //Przywracanie w³aœciwoœci kopca Maxheap w dó³
    void heapifyDown() {

        int index = 0;

        while (true) {

            int leftChildIndex = 2 * index + 1;
            int rightChildIndex = 2 * index + 2;
            int largestIndex = index;

            if (leftChildIndex < currentSize && heap[leftChildIndex].priority > heap[largestIndex].priority) {

                largestIndex = leftChildIndex;

            }

            if (rightChildIndex < currentSize && heap[rightChildIndex].priority > heap[largestIndex].priority) {

                largestIndex = rightChildIndex;

            }

            if (largestIndex != index) {

                std::swap(heap[index], heap[largestIndex]);
                    index = largestIndex;

            }
            else break;

        }

    }

    //Zmiana alokacji pamiêci
    void resize() {

        size_t newCapacity = capacity * 2;
        Element<T, P>* newHeap = new Element<T, P>[newCapacity];

        for (size_t i = 0; i < capacity; ++i) newHeap[i] = heap[i];

        delete[] heap;
        heap = newHeap;
        capacity = newCapacity;

    }

public:

    //Konstruktor
    PriorityQueue(int cap) : capacity(cap), currentSize(0) {

        heap = new Element<T, P>[capacity];

    }

    //Destruktor
    ~PriorityQueue() {

        delete[] heap;

    }

    //Dodanie elementu o okreœlonym priorytecie
    void insert(const T& value, const P& priority) {

        if (currentSize == capacity) resize();
            
        heap[currentSize++] = Element<T, P>(value, priority);
        heapifyUp();

    }

    //Usuniêcie elementu o najwiêkszym priorytecie
    T removeMax() {

        if (currentSize == 0) throw std::logic_error("Queue is empty");

        T maxValue = heap[0].value;
        std::swap(heap[0], heap[--currentSize]);
        heapifyDown();

        return maxValue;

    }

    // Zwrócenie rozmiaru kolejki
    size_t size() const {

        return currentSize;

    }

    //Peek - zwrócenie elementu o najwiêkszym priorytecie
    const T& peek() const {

        if (currentSize == 0) {

            throw std::logic_error("Queue is empty");

        }

        return heap[0].value;

    }

    // Modyfikacja priorytetu elementu (przekszta³cenie wstawianie elementu i usuwanie elementu o najwiêkszym priorytecie)
    void modifyPriority(const T& value, const P& newPriority) {

        for (size_t i = 0; i < currentSize; ++i) {

            if (heap[i].value == value) {

                heap[i].priority = newPriority;
                break;

            }

        }

        heapifyUp();
        heapifyDown();

    }

    void displayAllElements() const {

        cout << "Current elements in the priority queue:" << endl;

        for (size_t i = 0; i < currentSize; ++i) {

            cout << "Index: " << i << ", Value: " << heap[i].value << ", Priority: " << heap[i].priority << endl;
            

        }

        cout << "Capacity: " << capacity << ", Current size: " << currentSize << endl;

    }

};