#include <iostream>
using namespace std;

int length;
int tiles[] = {1, 1, 2, 4};

int main() {
  cin >> length;

  long long dp[length + 1] = {0};
  dp[0] = 1; // only one way to make a board of length 0 - no tiling
  dp[1] = 2;

  for (size_t i = 2; i <= length; i++) {
    for (int tile : tiles) {
      if (tile > i) { // skip the larger tiles
        continue;
      } else {
        dp[i] += dp[i - tile];
      }
    }
  }

  cout << dp[length] << endl;
  return 0;
}