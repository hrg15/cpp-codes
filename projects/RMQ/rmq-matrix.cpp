#include <climits>
#include <iostream>
using namespace std;

// A data structure with O(nˆ2) space and O(1) query time with simple array

const int MAX_N = 100;
int minTable[MAX_N][MAX_N];
int arr[MAX_N];

void preprocess(int n) {
  for (int i = 0; i < n; ++i) {
    minTable[i][i] = arr[i];
    for (int j = i + 1; j < n; ++j) {
      minTable[i][j] = min(minTable[i][j - 1], arr[j]);
    }
  }
}

int query(int i, int j) { return minTable[i][j]; }

int main() {
  int n = 6;
  int input[] = {1, 3, 2, 7, 9, 11};

  for (int i = 0; i < n; ++i) {
    arr[i] = input[i];
  }

  preprocess(n);

  cout << "Min(1, 4): " << query(1, 4) << endl;
  cout << "Min(0, 5): " << query(0, 5) << endl;

  return 0;
}
