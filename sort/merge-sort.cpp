#include "utils.h"
#include <iostream>

using namespace std;

void merge(int arr[], int p, int q, int r) {
  int n1 = q - p + 1;
  int n2 = r - q;

  int left[n1];
  int right[n2];

  for (int i = 0; i < n1; i++) {
    left[i] = arr[p + i];
  }
  for (int i = 0; i < n2; i++) {
    right[i] = arr[q + i + 1];
  }

  int i = 0;
  int j = 0;
  int k = p;
  while (i < n1 && j < n2) {
    if (left[i] <= right[j]) {
      arr[k] = left[i];
      i++;
    } else {
      arr[k] = right[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    arr[k++] = left[i++];
  }
  while (j < n2) {
    arr[k++] = right[j++];
  }
}

void mergeSort(int arr[], int p, int r) {
  if (p < r) {
    int q = (p + r) / 2;
    mergeSort(arr, p, q);
    mergeSort(arr, q + 1, r);
    merge(arr, p, q, r);
  }
}

int main() {
  int arr[] = {4, 2, 7, 1, 3};
  int n = sizeof(arr) / sizeof(arr[0]);

  mergeSort(arr, 0, n - 1);
  printArray(arr, n);

  return 0;
}