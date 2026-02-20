#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void initArray(double* arr, int n, double minValue, double maxValue) {
    for (int i = 0; i < n; i++) {
        arr[i] = minValue + (maxValue - minValue) * (rand() / (double)RAND_MAX);
        if (rand() % 2 == 0) {
            arr[i] = -arr[i];
        }
    }
}

void printArray(double* arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void reverseHalf(double* arr, int n) {
    int half = n / 2;
    for (int i = 0; i < half / 2; i++) {
        double temp = arr[i];
        arr[i] = arr[half - 1 - i];
        arr[half - 1 - i] = temp;
    }
}

void cyclicShiftLeft(double* arr, int n, int k) {
    k = k % n;
    for (int step = 0; step < k; step++) {
        double first = arr[0];
        for (int i = 0; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        arr[n - 1] = first;
    }
}

void selectionSort(double* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            double temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

void runTests() {
    cout << "=== Test Results ===" << endl;

    double test1[4] = { 1, 2, 3, 4 };
    reverseHalf(test1, 4);
    cout << "Test 1 (reverse first half): ";
    for (int i = 0; i < 4; i++) cout << test1[i] << " ";
    cout << " - Expected: 2 1 3 4" << endl;

    double test2[5] = { 1, 2, 3, 4, 5 };
    cyclicShiftLeft(test2, 5, 2);
    cout << "Test 2 (cyclic shift left by 2): ";
    for (int i = 0; i < 5; i++) cout << test2[i] << " ";
    cout << " - Expected: 3 4 5 1 2" << endl;

    double test3[5] = { 5, 2, 4, 1, 3 };
    selectionSort(test3, 5);
    cout << "Test 3 (selection sort): ";
    for (int i = 0; i < 5; i++) cout << test3[i] << " ";
    cout << " - Expected: 1 2 3 4 5" << endl;
}

int main() {
    srand(time(0));

    int n;
    double minValue, maxValue;

    cout << "Enter size of array: ";
    cin >> n;
    cout << "Enter min and max values: ";
    cin >> minValue >> maxValue;

    double* a = new double[n];

    initArray(a, n, minValue, maxValue);
    cout << "Initial array:" << endl;
    printArray(a, n);

    reverseHalf(a, n);
    cout << "After reversing first half:" << endl;
    printArray(a, n);

    int k = 2;
    cyclicShiftLeft(a, n, k);
    cout << "After cyclic shift left by " << k << ":" << endl;
    printArray(a, n);

    selectionSort(a, n);
    cout << "After selection sort:" << endl;
    printArray(a, n);

    runTests();

    delete[] a;

    return 0;
}