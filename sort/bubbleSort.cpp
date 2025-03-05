#include <iostream>
using namespace std;

void bubbleSort (int arr[], int n){
    for (int i = 0; i < n -1 ; i++){
        for (int j = 0; j < n - i -1; j++){
              if (arr[j] > arr[j + 1]){
                swap(arr[j], arr[j + 1]);
              }
        }
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

    bubbleSort(array, n);
    cout << "Sorted array:\n";
    printArray(array, n);

    return 0;
}