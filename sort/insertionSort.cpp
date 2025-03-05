#include <iostream>
using namespace std;

void insertionSort(int arr[], int n){
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i -1;
         
        while (j >= 0 && key < arr[j])
        {
            arr[j+1] = arr[j];
            --j;
        }
        arr[j+1] = key; 
    }
}

void printArray(int array[], int size) {
  for (int i = 0; i < size; i++) {
    cout << array[i] << " ";
  }
  cout << endl;
}


int main(){
    int n = 7;
    int array[] = {2, 5 , 55 , 85, 1, 4, 2};

    insertionSort(array, n);
    cout << "Sorted array in ascending order:\n";
    printArray(array, n);

    return 0;
}