#include <iostream>
#include <vector>
using namespace std;

int main() {
  int knapsackSize, itemsCnt;
  cin >> knapsackSize >> itemsCnt;

  vector<vector<int>> dp(itemsCnt + 1, vector<int>(knapsackSize + 1, 0));
  vector<pair<int, int>> items;
  items.push_back({0, 0}); // base case item

  int v, w;
  for (size_t i = 1; i <= itemsCnt; i++) {
    cin >> v >> w;
    items.push_back({v, w});
  }

  for (int row = 1; row <= itemsCnt; row++) {
    int value = items[row].first;
    int weight = items[row].second;

    for (int col = 1; col <= knapsackSize; col++) {
      // we don't pick the current item
      dp[row][col] = dp[row - 1][col]; // get the previous value

      // we pick the current value
      if (col >= weight                                          // there is space in the bag
          && dp[row - 1][col - weight] + value > dp[row][col]) { // consider including the current item and see if this would be more profitable
        dp[row][col] = dp[row - 1][col - weight] + value;
      }
    }
  }

  cout << dp[itemsCnt][knapsackSize] << endl;

  // restoring items selected
  int index = knapsackSize;

  for (int i = itemsCnt; i > 0; i--) {
    if (dp[i][index] != dp[i - 1][index]) {
      // we selected this item
      index = index - items[i].second;
      cout << "selected item: " << i << endl;
    }
  }

  return 0;
}