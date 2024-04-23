#include <iostream>
#include <stdexcept> // Dla obs³ugi wyj¹tków
#include "Element.hpp"

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
    void removeMax() {

        if (currentSize == 0) throw std::logic_error("Queue is empty");

        std::swap(heap[0], heap[--currentSize]);
        heapifyDown();

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

};

int main() {

    PriorityQueue<int, int> pq(10);

    // Dodanie elementów z okreœlonymi priorytetami
    pq.insert(1, 100);
    pq.insert(325, 200);
    pq.insert(7654, 50);
    pq.insert(2, 300);
    pq.insert(634, 150);
    pq.insert(86, 250);
    pq.insert(4, 75);
    pq.insert(2, 125);

    // Usuniêcie elementu o najwiêkszym priorytecie
    pq.removeMax();

    // Zwrócenie rozmiaru kolejki
    std::cout << "Size of the priority queue: " << pq.size() << std::endl;

    // Peek - zwrócenie elementu o najwiêkszym priorytecie
    std::cout << "Peek: " << pq.peek() << std::endl;

    // Modyfikacja priorytetu elementu
    pq.modifyPriority(325, 500);

    return 0;
}
