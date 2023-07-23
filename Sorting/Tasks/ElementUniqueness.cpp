#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool elementUniqueness(vector<int> &arr) {
  sort(arr.begin(), arr.end());

  for (size_t i = 0; i < arr.size() - 1; i++) {
    if (arr[i] == arr[i + 1]) {
      return false;
    }
  }

  return true;
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

  cout << boolalpha << "Contains unique elements: " << elementUniqueness(arr) << endl;

  return 0;
}