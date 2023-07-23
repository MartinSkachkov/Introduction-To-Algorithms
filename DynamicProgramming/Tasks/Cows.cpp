#include <iostream>
using namespace std;
const int MAX_DAYS = 50;
const int MAX_COWS = 1000;
int cows, n, q;
// cows - max number of cows per one farm
//  n - number of initial farms
//  q - queries for visits

int sum_row(int querie, int dp[MAX_DAYS + 1][MAX_COWS + 1]) {
  int farms = 0;

  for (size_t i = 1; i <= MAX_COWS; i++) {
    farms += dp[querie][i];
  }

  return farms;
}

int main() {
  cin >> cows >> n >> q;
  int dp[MAX_DAYS + 1][MAX_COWS + 1] = {0};

  for (size_t i = 1; i <= n; i++) {
    cin >> dp[0][i]; // initialize the first row of the table
  }

  for (size_t day = 0; day < MAX_DAYS; day++) {
    for (size_t i = 1; i <= cows; i++) {
      if (i <= cows / 2) {
        dp[day + 1][i * 2] += dp[day][i];
      } else {
        dp[day + 1][i] += 2 * dp[day][i];
      }
    }
  }

  int querie;
  for (size_t i = 0; i < q; i++) {
    cin >> querie;
    cout << sum_row(querie, dp) << endl;
  }

  cout << endl;
  return 0;
}