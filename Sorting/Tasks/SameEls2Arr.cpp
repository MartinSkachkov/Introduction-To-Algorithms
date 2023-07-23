#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void print(const vector<int> &arr) {
  for (int el : arr) {
    cout << el << ' ';
  }

  cout << endl;
}

void sameEls2Arr(vector<int> &arr1, vector<int> &arr2) {
  sort(arr1.begin(), arr1.end());
  print(arr1);
  sort(arr2.begin(), arr2.end());
  print(arr2);

  int i = 0, j = 0;

  while (i < arr1.size() && j < arr2.size()) {
    if (arr1[i] == arr2[j]) {
      cout << "element on index i=" << i << " equals to element on index j=" << j << endl;
      i++;
      j++;
    } else if (arr1[i] < arr2[j]) {
      i++;
    } else {
      j++;
    }
  }
}

int main() {
  vector<int> arr1, arr2;
  int n, m, num;
  cin >> n >> m;

  for (size_t i = 0; i < n; i++) {
    cin >> num;
    arr1.push_back(num);
  }

  for (size_t i = 0; i < m; i++) {
    cin >> num;
    arr2.push_back(num);
  }

  sameEls2Arr(arr1, arr2);

  return 0;
}