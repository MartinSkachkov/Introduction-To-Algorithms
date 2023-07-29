#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;

  int dp[n + 1][8];
  dp[0][7] = 1;

  for (int i = 1; i <= n; i++) {
    dp[i][0] += dp[i - 1][7];
    dp[i][1] += dp[i - 1][6];
    dp[i][3] += dp[i - 1][7];
    dp[i][3] += dp[i - 1][4];
    dp[i][4] += dp[i - 1][3];
    dp[i][6] += dp[i - 1][7];
    dp[i][6] += dp[i - 1][1];
    dp[i][7] += dp[i - 1][3];
    dp[i][7] += dp[i - 1][6];
    dp[i][7] += dp[i - 1][0];
  }

  cout << dp[n][7] << endl;
  return 0;
}