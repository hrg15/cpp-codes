#include <iostream>
#include <vector>
using namespace std;

long long countWays(int n, int k) {
  // Create a dynamic programming array to store the number of ways to reach
  // each step
  vector<long long> dp(n + 1, 0);

  // Base case: There is one way to reach the 0th step (starting point)
  dp[0] = 1;

  for (int i = 1; i <= n; i++) {
    // For each step i, consider all possible jumps from (i-1), (i-2), ...,
    // (i-k)
    for (int j = 1; j <= k && i - j >= 0; j++) {
      dp[i] += dp[i - j];
    }
  }
  return dp[n];
}

long long countWaysOptimized(int n, int k) {
  // Only need to keep track of the last k values
  vector<long long> dp(k + 1, 0);
  dp[0] = 1;

  for (int i = 1; i <= n; i++) {
    // Calculate the current position in our circular array
    int current = i % (k + 1);
    dp[current] = 0;

    // Sum up previous k values
    for (int j = 1; j <= k; j++) {
      if (i - j >= 0) {
        dp[current] += dp[(i - j) % (k + 1)];
      }
    }
  }

  return dp[n % (k + 1)];
}

int main() {
  int n = 5;
  int k = 3;

  cout << "Number of ways to climb " << n << " stairs with max " << k
       << " steps at a time: " << countWays(n, k) << endl;

  cout << "Using optimized space: " << countWaysOptimized(n, k) << endl;

  // Let's verify with a few test cases
  cout << "\nVerifying with additional test cases:" << endl;

  cout << "n=1, k=1: " << countWays(1, 1) << endl; // Should be 1

  cout << "n=2, k=2: " << countWays(2, 2) << endl; // Should be 2 (1+1 or 2)

  cout << "n=4, k=2: " << countWays(4, 2)
       << endl; // Should be 5 (1+1+1+1 or 1+1+2 or 1+2+1 or 2+1+1 or 2+2)

  return 0;
}