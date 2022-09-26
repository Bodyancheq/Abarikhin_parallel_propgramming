#include <iostream>
#include <omp.h>

using namespace std;

int main1() {

#pragma omp parallel for
    for (int i=0; i<4; i++)
    {
        cout << i << endl;
    }

#pragma omp parallel for
    for (int i=0; i<4; i++)
        for (int j=0; j<4; j++)
        {
            cout << i << " " << j << endl;
        }
    return 0;
}