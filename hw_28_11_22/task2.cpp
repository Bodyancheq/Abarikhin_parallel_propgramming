#include "iostream"
using namespace std;

template <class T>

void quickSort(T* a, const long n) {
    long i = 0, j = n-1;
    T pivot = a[n / 2];

    do {
        while (a[i] < pivot) {
            i++;
        }
        while (a[j] > pivot) {
            j--;
        }
        if (i <= j) {
            swap(a[i], a[j]);
            i++; j--;
        }
    } while (i <= j);

#pragma omp task shared(a)
    {
        if (j > 0) {
            quickSort(a, j+1);
        }
    }
#pragma omp task shared(a)
    {
        if (n > i) {
            quickSort(a + i, n - i);
        }
    }
#pragma omp taskwait
}


int main() {
    int n = 100;
    int randArray[n];
    for(int i=0;i<n;i++)
        randArray[i]=rand();
    quickSort(randArray, n);
    for(int i=0;i<n;i++)
        cout<<"Elements no "<<i+1<<"::"<<randArray[i]<<endl;
    return 0;
}