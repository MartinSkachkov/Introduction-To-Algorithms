#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int dp[n + 1]; // stores the number of ways we can reach the top from index i

  dp[n] = 1;
  dp[n - 1] = 1;
  n -= 2;

  while (n != -1) {
    dp[n] = dp[n + 1] + dp[n + 2]; // the number of ways we can reach the top from position n is to sum the # of ways we can reach the top with 1 step and # of ways we can reach the top with 2 steps
    n--;
  }

  return 0;
}