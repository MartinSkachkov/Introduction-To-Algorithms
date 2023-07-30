class Solution {
public:
  const int MAXN = 1000;
  int uniquePaths(int m, int n) {
    vector<vector<int>> dp(MAXN, vector<int>(MAXN, 0));

    for (int col = n - 1; col > -1; col--) {
      dp[m - 1][col] = 1;
    }

    for (int row = m - 1; row > -1; row--) {
      dp[row][n - 1] = 1;
    }

    for (int row = m - 2; row > -1; row--) {
      for (int col = n - 2; col > -1; col--) {
        dp[row][col] = dp[row + 1][col] + dp[row][col + 1];
      }
    }

    return dp[0][0];
  }
};