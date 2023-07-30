#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 100;
int amount = 10;
vector<int> coins = {10};

int main() {
  vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, 0));

  for (int row = 0; row < coins.size(); row++) {
    dp[row][0] = 1; // # if combinations to make amount 0 = 1 (don't take any coin)
  }

  for (int col = 1; col < amount + 1; col++) {
    if (col - coins[coins.size() - 1] < 0) {
      continue;
    } else {
      dp[coins.size() - 1][col] = dp[coins.size() - 1][col - coins[coins.size() - 1]];
    }
  }

  for (int row = coins.size() - 2; row > -1; row--) {
    for (int col = 1; col < amount + 1; col++) {
      dp[row][col] = dp[row][col - coins[row]] + dp[row + 1][col];
    }
  }

  cout << dp[0][amount];

  return 0;
}