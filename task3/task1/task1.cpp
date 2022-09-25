#include <iostream>
#include <omp.h>
#include <chrono>
#include "task2.cpp"
using namespace std::chrono;
using namespace std;


//Vectors
//Non Parallel 15100
//OMP-parallel 233100
//Matrices
//Non Parallel 2900
//OMP-parallel 49800

int main2();

int main() {
    cout << "Vectors" << endl;
    int N = 10000;
    int vector1[N];
    int vector2[N];
    int sum[N];

    for (int i = 0; i < N; i++) {
        vector1[i] = rand();
        vector2[i] = rand();
    }

    auto start = high_resolution_clock::now();
    for (int i = 0; i < N; i++) {
        sum[i] = vector1[i] + vector2[i];
    }
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(end - start);
    cout << "Non Parallel " << duration.count() << endl;

    start = high_resolution_clock::now();
#pragma omp parallel for
    for (int i = 0; i < N; i++) {
        sum[i] = vector1[i] + vector2[i];
    }

    end = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(end - start);
    cout << "OMP-parallel " << duration.count() << endl;

    main2();
    return 0;
}