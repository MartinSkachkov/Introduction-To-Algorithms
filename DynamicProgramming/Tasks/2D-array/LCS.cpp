class Solution {
public:
  const int MAXN = 1005;
  int longestCommonSubsequence(string text1, string text2) {
    vector<vector<int>> dp(MAXN, vector<int>(MAXN, 0));
    int n = text1.size();
    int m = text2.size();

    for (int row = n - 1; row > -1; row--) {
      for (int col = m - 1; col > -1; col--) {
        if (text1[row] == text2[col]) {
          dp[row][col] = 1 + dp[row + 1][col + 1];
        } else {
          dp[row][col] = max(dp[row + 1][col], dp[row][col + 1]);
        }
      }
    }
    return dp[0][0];
  }
};