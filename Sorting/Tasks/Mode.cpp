#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int findMode(vector<int> &arr) {
  sort(arr.begin(), arr.end());

  int mode = arr[0];
  int m = 1;
  int s = 0;
  for (size_t i = 1; i < arr.size(); i++) {
    if (arr[i] == arr[i - 1]) {
      if (arr[i] == mode) {
        m++;
      } else {
        s++;
        if (s > m) {
          mode = arr[i];
          m = s;
        }
      }
    } else {
      s = 1;
    }
  }

  return mode;
}

int main() {
  vector<int> arr;
  int n, num;
  cin >> n;

  for (size_t i = 0; i < n; i++) {
    cin >> num;
    arr.push_back(num);
  }

  cout << "Mode is: " << findMode(arr) << endl;

  return 0;
}