#include <iostream>
using namespace std;

void merge(int a[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int *x = new int[n1];
    int *y = new int[n2];

    for (int i = 0; i < n1; i++)
        x[i] = a[l + i];

    for (int i = 0; i < n2; i++)
        y[i] = a[m + 1 + i];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (x[i] <= y[j])
            a[k++] = x[i++];
        else
            a[k++] = y[j++];
    }

    while (i < n1)
        a[k++] = x[i++];

    while (j < n2)
        a[k++] = y[j++];

    delete[] x;
    delete[] y;
}

void mergeSortRecursive(int a[], int l, int r) {
    if (l >= r)
        return;

    int m = l + (r - l) / 2;

    mergeSortRecursive(a, l, m);
    mergeSortRecursive(a, m + 1, r);
    merge(a, l, m, r);
}

void mergeSortIterative(int a[], int n) {
    for (int size = 1; size < n; size *= 2) {
        for (int l = 0; l < n - 1; l += 2 * size) {
            int m = l + size - 1;
            int r = l + 2 * size - 1;

            if (m >= n - 1)
                continue;

            if (r >= n)
                r = n - 1;

            merge(a, l, m, r);
        }
    }
}

void display(int a[], int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

int main() {
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int *a = new int[n];
    int *b = new int[n];

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }

    mergeSortRecursive(a, 0, n - 1);
    mergeSortIterative(b, n);

    cout << "Recursive Merge Sort: ";
    display(a, n);

    cout << "Iterative Merge Sort: ";
    display(b, n);

    delete[] a;
    delete[] b;

    return 0;
}