#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int rodCutting(const vector<int> &price, int n) {
  vector<int> dp(n + 1, 0); // dp[i] = بیشترین درآمد برای طول i

  for (int i = 1; i <= n; i++) {
    int max_val = 0;
    for (int j = 1; j <= i; j++) {
      max_val = max(max_val, price[j - 1] + dp[i - j]);
    }
    dp[i] = max_val;
  }

  return dp[n];
}

int main() {
  vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};
  int n = 8;
  cout << "بیشترین سود قابل دستیابی: " << rodCutting(price, n) << endl;
  return 0;
}
