#include <stdio.h>
#include <iostream>
#include <omp.h>
#include <string>
using namespace std;

int main4(int argc, char *argv[]) {
    setlocale(LC_ALL, "Russian");
    int n;

#pragma omp parallel private(n)
    {
        n = omp_get_thread_num();

#pragma omp sections
        {
#pragma omp section
            {
                printf("Section 1, thread %d - %d\n", n,
                       omp_get_thread_num());
            }
        }
    }
}