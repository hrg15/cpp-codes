#include <iostream>
#include "utils.h"
using namespace std;

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int n = 7;
    int array[] = {2, 5, 55, 85, 1, 4, 2};

    insertionSort(array, n);
    cout << "Sorted array:\n";
    printArray(array, n);

    return 0;
}