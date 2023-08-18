class Solution {
public:
  int maximalSquare(vector<vector<char>> &matrix) {
    int maxArea = 0;
    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<vector<int>> dp(rows + 1, vector<int>(cols + 1, 0));
    for (int i = 1; i <= cols; i++) {
      dp[1][i] = matrix[1][i];
      maxArea = max(maxArea, dp[1][i]);
    }

    for (int i = 2; i <= rows; i++) {
      dp[i][1] = matrix[i][1];
      maxArea = max(maxArea, dp[i][1]);

      for (int j = 2; j <= cols; j++) {
        dp[i][j] = matrix[i][j] * (1 + min({matrix[i - 1][j], matrix[i - 1][j - 1], matrix[i][j - 1]}));
        maxArea = max(maxArea, dp[i][j]);
      }
    }

    return maxArea * maxArea;
  }
};