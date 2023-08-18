#include <iostream>
#include <string>
#include <vector>
using namespace std;

int calculateLen(const string &str) {
  vector<vector<int>> dp(str.size() + 1, vector<int>(str.size() + 1, 1));
  int n = str.size();

  // base case subsequences with length 2
  for (size_t i = 1; i <= n - 1; i++) {
    if (str[i - 1] == str[i]) {
      dp[i][i + 1] = 2;
    }
  }

  // subsequnces with length at least 3
  for (size_t k = 2; k <= n - 1; k++) {
    for (size_t i = 1; i <= n - k; i++) {
      if (str[i - 1] == str[i + k - 1]) {
        dp[i][i + k] = 2 + dp[i + 1][i + k - 1];
      } else {
        dp[i][i + k] = max(dp[i + 1][i + k], dp[i][i + k - 1]);
      }
    }
  }

  return dp[1][n];
}

int main() {
  string input = "bbbab";

  cout << calculateLen(input) << endl;

  return 0;
}