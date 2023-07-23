#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;
vector<vector<int>> res;

void threeSum() {
  sort(arr.begin(), arr.end());

  for (size_t i = 0; i < arr.size() - 2; i++) {
    // conditions for no duplicates
    if (i == 0 || (i > 0 && arr[i] != arr[i - 1])) {
      // two sum
      int leftId = i + 1;
      int rightId = arr.size() - 1;
      int target = 0 - arr[i];

      while (leftId < rightId) {
        if (arr[leftId] + arr[rightId] == target) {
          res.push_back({arr[i], arr[leftId], arr[rightId]});
          while (leftId < rightId && arr[leftId] == arr[leftId + 1])
            leftId++;
          while (leftId < rightId && arr[rightId] == arr[rightId - 1])
            rightId--;
          leftId++;
          rightId--;
        } else if (arr[leftId] + arr[rightId] > target) {
          rightId--;
        } else {
          leftId++;
        }
      }
    }
  }
}

int main() {
  int n, num;
  cin >> n;

  for (size_t i = 0; i < n; i++) {
    cin >> num;
    arr.push_back(num);
  }

  threeSum();

  for (size_t i = 0; i < res.size(); i++) {
    for (int el : res[i]) {
      cout << el << ' ';
    }
    cout << endl;
  }

  return 0;
}