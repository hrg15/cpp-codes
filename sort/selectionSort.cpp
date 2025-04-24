#include <iostream>
#include "utils.h"
using namespace std;

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

int main() {
    int n = 7;
    int array[] = {2, 5, 55, 85, 1, 4, 2};

    selectionSort(array, n);
    cout << "Sorted array:\n";
    printArray(array, n);

    return 0;
}