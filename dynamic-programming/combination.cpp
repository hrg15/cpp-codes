#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<string, int> memo;

// recursive normall function
int combination(int n, int m) {
  if (n == 0 || m == 0 || n == m) {
    return 1;
  }

  return combination(n - 1, m) + combination(n - 1, m - 1);
}

// recursive memoization
int comb_dp1(int n, int m) {
  if (m == 0 || n == 0 || m == n) {
    return 1;
  }
  string key = to_string(n) + "" + to_string(m);
  if (memo.count(key)) {
    return memo[key];
  }

  memo[key] = comb_dp1(n - 1, m) + comb_dp1(n - 1, m - 1);
  return memo[key];
}

// button-up
int comb_dp2(int n, int m) {
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= min(i, m); ++j) {
      if (j == 0 || j == i) {
        dp[i][j] = 1;
      } else {
        dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
      }
    }
  }
  return dp[n][m];
}
// Bottom-up optimization
int comb_dp3(int n, int m) {
  vector<int> dp(m + 1, 0);
  dp[0] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = min(i, m); j > 0; --j) {
      dp[j] += dp[j - 1];
    }
  }
  return dp[m];
}

int main() {
  int n = 20;
  int m = 12;

  int result = combination(n, m);
  int result1 = comb_dp1(n, m);
  int result2 = comb_dp2(n, m);
  int result3 = comb_dp3(n, m);
  cout << " The result: " << result;
  cout << "\n The result memoization: " << result1;
  cout << "\n The result bottom-up: " << result2;
  cout << "\n The result bottom-up: " << result3;

  return 0;
}