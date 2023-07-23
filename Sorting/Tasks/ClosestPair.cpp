#include <algorithm>
#include <iostream>
#include <limits.h>
#include <utility>
#include <vector>
using namespace std;

pair<int, int> closestPair(vector<int> &arr) { // theta(nlogn)
  sort(arr.begin(), arr.end());                // theta(nlogn)

  int closest = INT_MAX, first = -1, second = -1;
  for (size_t i = 0; i < arr.size() - 1; i++) { // theta(n)
    if (closest > arr[i + 1] - arr[i]) {
      closest = arr[i + 1] - arr[i];
      first = arr[i];
      second = arr[i + 1];
    }
  }

  return {first, second};
}

int main() {
  int n, num;
  cout << "n: ";
  cin >> n;

  vector<int> arr;
  for (size_t i = 0; i < n; i++) {
    cin >> num;
    arr.push_back(num);
  }

  pair<int, int> res = closestPair(arr);

  cout << '(' << res.first << ", " << res.second << ")\n";

  return 0;
}