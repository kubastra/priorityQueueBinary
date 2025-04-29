#include "kopiec.h"
#include <chrono>
#include <fstream>

std::ofstream file("time.dat");
#define MAX 10000
#define REPEAT 10

void test() {
    Kopiec kop;

    kop.inserta(10);
    kop.inserta(12);
    kop.inserta(13);
    kop.inserta(14);
    kop.inserta(15);
    kop.inserta(16);

    kop.print();
    std::cout << std::endl;

    kop.pop_min();

    kop.print();
}

void pop_measure(int size) {
    auto dur = 0;
    for (int l = 0; l < REPEAT; l++){

        Kopiec kop;

        for (int i = size; i > 0; i--) {
            kop.inserta(i);
        }

        auto start = std::chrono::high_resolution_clock::now();
        kop.pop_min();
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
        dur+=duration;
    }
        dur = dur/REPEAT;

    file << size << " " << dur << "\n";
}
int main() {
    if (!file.is_open()) {
        std::cout << "file not open";
        return -1;
    }

    for (int i = 1; i < MAX; i++) {
        pop_measure(i);
        if (i > 50 ) i += 10;
    }

    return 0;
}