// 2-D version
class Solution {
public:
  const long long MAXN = 5000;
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    vector<vector<long long>> dp(MAXN, vector<long long>(MAXN, 0));

    int rows = obstacleGrid.size();
    int cols = obstacleGrid[1].size();

    if (obstacleGrid[rows - 1][cols - 1] == 1) {
      return 0;
    } else {

      dp[rows - 1][cols - 1] = 1; // base case
      // filling the las row
      for (int c = cols - 2; c > -1; c--) {
        if (obstacleGrid[rows - 1][c] == 0) { // free
          dp[rows - 1][c] = dp[rows][c] + dp[rows - 1][c + 1];
        } else { // obstacle
          dp[rows - 1][c] = 0;
        }
      }

      // filling the rest of the matrix
      for (int r = rows - 2; r > -1; r--) {
        for (int c = cols - 1; c > -1; c--) {
          if (obstacleGrid[r][c] == 0) { // free
            dp[r][c] = dp[r + 1][c] + dp[r][c + 1];
          } else { // obstacle
            dp[r][c] = 0;
          }
        }
      }
      return dp[0][0];
    }
  }
};

// 1-D version

class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>> &grid) {

    int m = grid.size(), n = grid[0].size();
    if (grid[m - 1][n - 1] == 1 || grid[0][0] == 1)
      return 0;
    vector<long long> dp(n);
    dp[n - 1] = 1;
    for (int i = m - 1; i >= 0; i--) {
      for (int j = n - 1; j >= 0; j--) {
        if (grid[i][j] == 1)
          dp[j] = 0;
        else if (j == n - 1)
          continue;
        else
          dp[j] = dp[j] + dp[j + 1];
      }
    }
    return dp[0];
  }
};