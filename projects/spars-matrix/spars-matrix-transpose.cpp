#include <iostream>
using namespace std;
#define MAX 100

struct spars {
  int row;
  int col;
  int value;
};

void sparsTranspose(spars mat[], spars transpose[]) {
  transpose[0].col = mat[0].row;
  transpose[0].row = mat[0].col;
  transpose[0].value = mat[0].value;

  int k = 1;
  for (int i = 0; i < mat[0].col; i++) {
    for (int j = 1; j <= mat[0].value; j++) {
      if (mat[j].col == i) {
        transpose[k].row = mat[j].col;
        transpose[k].col = mat[j].row;
        transpose[k].value = mat[j].value;
        k++;
      }
    }
  }
}

void printSparse(spars mat[]) {
  int count = mat[0].value;
  printf("Row\tCol\tValue\n");
  for (int i = 0; i <= count; i++) {
    printf("%d\t%d\t%d\n", mat[i].row, mat[i].col, mat[i].value);
  }
}

int main() {
  spars mat[MAX] = {{4, 5, 4}, {0, 2, 3}, {1, 4, 5}, {3, 0, 6}, {3, 1, 7}};

  spars trans[MAX];

  printf("Original Sparse Matrix:\n");
  printSparse(mat);

  // فراخوانی ترانهاده
  sparsTranspose(mat, trans);

  printf("\nTransposed Sparse Matrix:\n");
  printSparse(trans);

  return 0;
}