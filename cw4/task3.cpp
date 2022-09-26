#include <stdio.h>
#include <iostream>
#include <omp.h>
using namespace std;

int main3(int argc, char *argv[]) {
    setlocale(LC_ALL, "Russian");
    int n;
    omp_set_nested(1);

#pragma omp parallel private(n)
    {
        n = omp_get_thread_num();

#pragma omp parallel
        {
            printf("Part 1, thread %d - %d\n", n,
                   omp_get_thread_num());
        }
    }
    omp_set_nested(0);
}