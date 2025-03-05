#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx])
                minIdx = j;
        }
        swap(arr[i], arr[minIdx]);
    }
}


void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
      cout << array[i] << " ";
    }
    cout << endl;
  }
  
  
  int main (){
      int n = 7;
      int array[] = {2, 5 , 55 , 85, 1, 4, 2};
  
      selectionSort(array, n);
      cout << "Sorted array:\n";
      printArray(array, n);
  
      return 0;
  }