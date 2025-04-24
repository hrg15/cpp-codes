#ifndef UTILS_H
#define UTILS_H

#include <iostream>
using namespace std;

void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

#endif 