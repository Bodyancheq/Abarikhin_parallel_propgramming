#include <iostream>
#include <omp.h>
#include <chrono>
using namespace std::chrono;
using namespace std;

int main2() {
    cout << "Matrices" << endl;

    int N = 10;
    int arr1[N][N];
    int arr2[N][N];
    int sum[N][N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++){
            arr1[i][j] = rand();
            arr2[i][j] = rand();
        }
    }

    auto start = high_resolution_clock::now();
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < N; k++){
            for (int j = 0; j < N; j++) {
                sum[i][j] = arr1[i][k] + arr2[k][j];
            }
        }
    }
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(end - start);
    cout << "Non Parallel " << duration.count() << endl;

    start = high_resolution_clock::now();
#pragma omp parallel for
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < N; k++){
            for (int j = 0; j < N; j++) {
                sum[i][j] = arr1[i][k] + arr2[k][j];
            }
        }
    }
    end = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(end - start);
    cout << "OMP-parallel " << duration.count() << endl;
    return 0;
}