#include <bits/stdc++.h>
using namespace std;
// function to find maximum sum is divisble by three
int max_sum(int arr[], int n) {
  int dp[n][3];
  memset(dp, 0, sizeof(dp));
  dp[0][arr[0] % 3] = arr[0];
  for (int i = 1; i < n; i++) {
    int num = arr[i];
    // if remainder is 0
    if (num % 3 == 0) {
      dp[i][0] = dp[i - 1][0] + num;
      dp[i][1] = dp[i - 1][1] > 0 ? dp[i - 1][1] + num : 0;
      dp[i][2] = dp[i - 1][2] > 0 ? dp[i - 1][2] + num : 0;
    }
    // if remainder is 1
    else if (num % 3 == 1) {
      dp[i][0] = max(dp[i - 1][0], dp[i - 1][2] > 0 ? dp[i - 1][2] + num : 0);
      dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + num);
      dp[i][2] = dp[i - 1][1] > 0 ? dp[i - 1][1] + num : 0;
    }
    // if remainder is 2
    else {
      dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] > 0 ? dp[i - 1][1] + num : 0);
      dp[i][1] = max(dp[i - 1][1], dp[i - 1][2] > 0 ? dp[i - 1][2] + num : 0);
      dp[i][2] = max(dp[i - 1][2], dp[i - 1][0] + num);
    }
  }
  return dp[n - 1][0];
}
// driver function
int main() {
  int n;
  cin >> n; // number of elements in array
  int arr[n];
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  int ans = max_sum(arr, n);
  cout << "The Maximum sum is divisible by three is : " << ans;
}