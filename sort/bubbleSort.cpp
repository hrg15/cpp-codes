#include <iostream>
#include "utils.h"
using namespace std;

void bubbleSort (int arr[], int n){
    for (int i = 0; i < n ; i++){
        // After each iteration, the largest element 'bubbles' to the end
        // So we don't need to compare with the last i elements that are already sorted
        for (int j = 0; j < n - i -1; j++){ 
              if (arr[j] > arr[j + 1]){
                swap(arr[j], arr[j + 1]);
              }
        }
    }
}

int main (){
    int n = 7;
    int array[] = {2, 5 , 55 , 85, 1, 4, 2};

    bubbleSort(array, n);
    cout << "Sorted array:\n";
    printArray(array, n);

    return 0;
}