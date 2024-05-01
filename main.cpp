#include <iostream>
#include <chrono>
#include "MaxHeap.cpp"
using namespace std;
using namespace chrono;

void test_full(int size) {

    double total_time = 0.0;
    
    for (int i = 0; i < 100; i++) {

        //Tworzymy kopiec do testów
        PriorityQueue<int, int> pq(size);
        for (int i = 0; i < size; i++) {

            pq.insert(i, i);

        }

        auto start_time = high_resolution_clock::now();

        pq.insert(5, -1); //W prawym argumencie dajemy size+1 lub size/2 lub -1

        auto end_time = high_resolution_clock::now();

        auto duration = duration_cast<nanoseconds>(end_time - start_time);
        total_time += duration.count();
        
    }
    
    double average_time = total_time / 100;

    cout << "Sredni czas dodania elementu do pelnego kopca na koniec dla " << size << " elementow to " << average_time << endl;

}

void test_free(int size) {

    double total_time = 0.0;

    for (int i = 0; i < 100; i++) {

        //Tworzymy kopiec do testów
        PriorityQueue<int, int> pq(size + 1);
        for (int i = 0; i < size; i++) {

            pq.insert(i, i);

        }

        auto start_time = high_resolution_clock::now();

        pq.insert(5, -1); //W prawym argumencie dajemy size+1 lub size/2 lub -1

        auto end_time = high_resolution_clock::now();

        auto duration = duration_cast<nanoseconds>(end_time - start_time);
        total_time += duration.count();

    }

    double average_time = total_time / 100;

    cout << "Sredni czas dodania elementu do wolnego kopca na koniec dla " << size << " elementow to " << average_time << endl;

}

void test_remove(int size) {

    double total_time = 0.0;

    for (int i = 0; i < 100; i++) {

        //Tworzymy kopiec do testów
        PriorityQueue<int, int> pq(size);
        for (int i = 0; i < size; i++) {

            pq.insert(i, i);

        }

        auto start_time = high_resolution_clock::now();

        int x = pq.removeMax();

        auto end_time = high_resolution_clock::now();

        auto duration = duration_cast<nanoseconds>(end_time - start_time);
        total_time += duration.count();

    }

    double average_time = total_time / 100;

    cout << "Sredni czas usuniecia elementu o najwiekszym priorytecie i zwrocenie jego wartosci dla " << size << " elementow to " << average_time << endl;

}

void test_peek(int size) {

    double total_time = 0.0;

    for (int i = 0; i < 100; i++) {

        //Tworzymy kopiec do testów
        PriorityQueue<int, int> pq(size);
        for (int i = 0; i < size; i++) {

            pq.insert(i, i);

        }

        auto start_time = high_resolution_clock::now();

        int x = pq.peek();

        auto end_time = high_resolution_clock::now();

        auto duration = duration_cast<nanoseconds>(end_time - start_time);
        total_time += duration.count();

    }

    double average_time = total_time / 100;

    cout << "Sredni czas podejzenia wartosci najwiekszej dla " << size << " elementow to " << average_time << endl;

}

int main() {

    /*
    test_full(10);
    test_free(10);
    test_full(100);
    test_free(100);
    test_full(1000);
    test_free(1000);
    test_full(10000);
    test_free(10000);
    test_full(100000);
    test_free(100000);
    test_full(1000000);
    test_free(1000000);
    */
    /*
    test_remove(10);
    test_remove(100);
    test_remove(1000);
    test_remove(10000);
    test_remove(100000);
    test_remove(1000000);
    */

    test_peek(10);
    test_peek(100);
    test_peek(1000);
    test_peek(10000);
    test_peek(100000);
    test_peek(1000000);

    return 0;
}