#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int r_min = 0;
    int r_max = 1;

    int n = 100;

    double X1, X2, M1, M2;
    double r[n + 1], y[n + 1], D[n + 1], F[n + 1], A[n + 1], B[n + 1], C[n + 1], f[n + 1], a[n + 1], b[n + 1];

    double h = (r_max - r_min) / double(n);

    X1 = 0;
    X2 = 0;

    M1 = 0;
    M2 = 1;

    a[1] = X1;
    b[1] = M1;

    A[0] = 0;
    B[n] = 0;
    C[0] = 0;
    C[n] = 0;

    for (int i = 0; i < n + 1; i ++){
        r[i] = r_min + i * h;
        D[i] = r[i];
        F[i] = 4 * r[i];
        f[i] = -1 * F[i] * h * h;
    }

    for (int i = 0; i < n; i ++) {
        A[i] = D[i];
        B[i] = D[i + 1];
        C[i] = D[i] + D[i + 1];
    }
    A[n] = D[n];

    for (int i = 1; i < n; ++i) {
        a[i + 1] = B[i] / (C[i] - a[i] * A[i]);
        b[i + 1] = (f[i] + A[i] * b[i]) / (C[i] - a[i] * A[i]);
    }

    y[n] = (M2 + X2 * b[n]) / (1 - X2 * a[n]);

    for (int i = n - 1; i > -1; --i) {
        y[i] = a[i + 1] * y[i + 1] + b[i + 1];
    }

    cout << endl;
    for (int i = 0; i < n + 1; ++i) {
        cout << abs(y[i] - r[i] * r[i]) << " ";
    }

    return 0;
}
