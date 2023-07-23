#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int binarySearch(const vector<int> &arr, int key) {
  int l = 0;
  int r = arr.size() - 1;

  while (l <= r) {
    int mid = (l + r) / 2;
    if (arr[mid] == key) {
      return mid;
    } else if (key < arr[mid]) {
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }

  return -1;
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

  sort(arr.begin(), arr.end());

  int key;
  cout << "key: ";
  cin >> key;
  cout << "found element at index: " << binarySearch(arr, key) + 1 << endl; // 1-based indexing

  return 0;
}