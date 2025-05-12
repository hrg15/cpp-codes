#include <iostream>
#include <string>
#include <vector>
using namespace std;

string longestCommonSubstring(const string &X, const string &Y) {
  int n = X.length();
  int m = Y.length();

  // Create DP table - dp[i][j] represents length of LCS ending at X[i-1] and
  // Y[j-1]
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

  int maxLength = 0;
  int endPosition = 0;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (X[i - 1] == Y[j - 1]) {
        // If current characters match, extend the previous match
        dp[i][j] = dp[i - 1][j - 1] + 1;

        if (dp[i][j] > maxLength) {
          maxLength = dp[i][j];
          endPosition = i - 1;
        }
      }
      // If characters don't match, LCS ending here has length 0 (default)
    }
  }

  return X.substr(endPosition - maxLength + 1, maxLength);
}

int main() {
  string X = "photograph";
  string Y = "tomography";

  cout << "String X: " << X << endl;
  cout << "String Y: " << Y << endl;

  string lcs = longestCommonSubstring(X, Y);

  cout << "Longest Common Substring: " << lcs << endl;
  cout << "Length: " << lcs.length() << endl;

  X = "ABCDEF";
  Y = "XABCDE";
  cout << "\nString X: " << X << endl;
  cout << "String Y: " << Y << endl;
  cout << "Longest Common Substring: " << longestCommonSubstring(X, Y) << endl;

  X = "ABABC";
  Y = "BABCA";
  cout << "\nString X: " << X << endl;
  cout << "String Y: " << Y << endl;
  cout << "Longest Common Substring: " << longestCommonSubstring(X, Y) << endl;

  return 0;
}