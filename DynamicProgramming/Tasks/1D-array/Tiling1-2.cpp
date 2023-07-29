#include <iostream>
using namespace std;

int length;

int main() {
  cin >> length;

  int dp[length + 1] = {0};
  dp[1] = 1;
  dp[2] = 2;
  for (size_t i = 3; i <= length; i++) {
    dp[i] = dp[i - 1] + dp[i - 2];
  }

  cout << dp[length] << endl;
  return 0;
}