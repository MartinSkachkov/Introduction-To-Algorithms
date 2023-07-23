#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

vector<int> arr;
int target;

pair<int, int> twoSum() {
  sort(arr.begin(), arr.end());
  int leftId = 0, rightId = arr.size() - 1;
  int sum;

  while (leftId != rightId && leftId < rightId) { // even len: l&r point to the same; odd len: they surpass each other
    sum = arr[leftId] + arr[rightId];

    if (sum > target) {
      rightId--;
    } else if (sum < target) {
      leftId++;
    } else {                            // equal
      return {leftId + 1, rightId + 1}; // in the task it is said it's one based id
    }
  }

  cout << "Couldn't find two sum!\n";
  return {-1, -1};
}

int main() {
  int n, num;
  cin >> n >> target;

  for (size_t i = 0; i < n; i++) {
    cin >> num;
    arr.push_back(num);
  }

  pair<int, int> res = twoSum();
  cout << '[' << res.first << ", " << res.second << ']';

  return 0;
}