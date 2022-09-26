#include <stdio.h>
#include <iostream>
#include <omp.h>

using namespace std;

int main2(int argc, char *argv[])
{
    setlocale(LC_ALL, "Russian");
    printf("Value OMP_DYNAMIC: %d\n", omp_get_dynamic());
    omp_set_dynamic(1);
    printf("Value OMP_DYNAMIC: %d\n", omp_get_dynamic());

#pragma omp parallel num_threads(128)
    {
#pragma omp master
        {
            printf("Parallel scope, %d threads\n",
                   omp_get_num_threads());
        }
    }
}