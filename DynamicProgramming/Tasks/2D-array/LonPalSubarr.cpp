#include <iostream>
#include <string>
#include <vector>
using namespace std;

int calculateLen(const string &str) {
  vector<vector<bool>> dp(str.size() + 1, vector<bool>(str.size() + 1, false));
  int n = str.size();
  int maxLen = 0;

  // base case when we have one letter
  for (size_t i = 1; i <= n; i++) {
    dp[i][i] = true;
    maxLen = 1;
  }

  // base case when we have two letters
  for (size_t i = 1; i <= n; i++) {
    dp[i][i + 1] = (str[i - 1] == str[i]);
    if (dp[i][i + 1]) {
      maxLen = 2;
    }
  }

  // case when we have substring with length 3 and more
  for (size_t k = 2; k <= n - 1; k++) {
    for (size_t i = 1; i <= n - k; i++) {
      dp[i][i + k] = (str[i - 1] == str[i + k - 1] && dp[i + 1][i + k - 1]);
      if (dp[i][i + k]) {
        maxLen = k + 1;
      }
    }
  }

  return maxLen;
}

int main() {
  string input = "aaabcba";

  cout << calculateLen(input) << endl;

  return 0;
}