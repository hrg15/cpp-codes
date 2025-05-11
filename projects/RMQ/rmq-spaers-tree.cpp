
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

// this is another way for RMQ (Range Minimum Query)
// A data structure with O(n) space and O(log n) query time with Spars Tree

vector<int> tree;

void build_segment_tree(const vector<int> &arr) {
  int n = arr.size();
  tree.resize(2 * n);

  for (int i = 0; i < n; i++) {
    tree[n + i] = arr[i];
  }

  for (int i = n - 1; i > 0; i--) {
    tree[i] = min(tree[2 * i], tree[2 * i + 1]);
  }
}

int query(int l, int r, int n) {

  l += n;
  r += n;

  int result = INT_MAX;

  while (l <= r) {
    if (l % 2 == 1) {
      result = min(result, tree[l]);
      l++;
    }
    if (r % 2 == 0) {
      result = min(result, tree[r]);
      r--;
    }
    l /= 2;
    r /= 2;
  }

  return result;
}

int main() {
  vector<int> arr = {3, 1, 4, 1, 5, 9, 2, 6};
  int n = arr.size();

  build_segment_tree(arr);

  cout << "Min in range [0, 4]: " << query(0, 4, n) << endl;
  cout << "Min in range [2, 5]: " << query(2, 5, n) << endl;

  return 0;
}