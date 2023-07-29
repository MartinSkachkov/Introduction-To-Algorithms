class Solution {
public:
  const int MAX = 1000000;

  int coinChange(vector<int> &coins, int amount) {
    int *dp = new int[amount + 1];
    dp[0] = 0; // how many coins are needed to create an amount of zero... zero coins

    for (int i = 1; i <= amount; i++) {
      dp[i] = MAX;
      for (int j = 0; j < coins.size(); j++) {
        if (i >= coins[j]) { // we can use this coin i
          dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
          // 1 means use the current coint and add the number of coins needed to create the remaining amount
          // coins = [1,3,4,5]
          // dp[7] = (use coin 1) 1 + (#coins to create amount 6) dp[6]
          // dp[7] = (use coin 3) 1 + (#coins to create amount 4) dp[4]
          // dp[7] = (use coin 4) 1 + (#coins to create amount 3) dp[3]
          // dp[7] = (use coin 5) 1 + (#coins to create amount 2) dp[2]
          // and we want the min of all of them
        }
      }
    }

    int res = dp[amount];
    delete[] dp;
    if (res == MAX) {
      return -1;
    }
    return res;
  }
};