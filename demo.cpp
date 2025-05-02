#include <bits/stdc++.h>
using namespace std;

void func(int a[], int b[], int n) {
    for (int i = 0; i < n; i++) {
        a[i] = a[i] * a[i];
        b[i] = b[i] * b[i];
    }
}

void summ(int a[], int b[], int sum[], int n) {
    for (int i = 0; i < n; i++) {
        sum[i] = a[i] + b[i];
    }
}

int main() {
    int a[] = {1, 2, 3, 4, 5};
    int b[] = {6, 7, 8, 9, 10};
    int n = sizeof(a) / sizeof(a[0]);

    func(a, b, n);

    int sum[n];
    summ(a, b, sum, n);

    for (int i = 0; i < n; i++) {
        cout << sum[i] << " ";
    }

    return 0;
}
