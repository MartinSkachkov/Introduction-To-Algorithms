#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int median(vector<int> &arr, int n) {
  sort(arr.begin(), arr.end());
  return arr[n / 2];
}

int main() {
  vector<int> arr;
  int n, num;
  cin >> n;

  for (size_t i = 0; i < n; i++) {
    cin >> num;
    arr.push_back(num);
  }

  cout << median(arr, n) << endl;

  return 0;
}