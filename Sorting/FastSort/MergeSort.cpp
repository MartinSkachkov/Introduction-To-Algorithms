#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &leftSub, vector<int> &rightSub, vector<int> &arr) {
  int i = 0, l = 0, r = 0;

  while (l < leftSub.size() && r < rightSub.size()) {
    if (leftSub[l] < rightSub[r]) {
      arr[i] = leftSub[l];
      i++;
      l++;
    } else {
      arr[i] = rightSub[r];
      i++;
      r++;
    }
  }

  // copy the rest
  while (l < leftSub.size()) {
    arr[i] = leftSub[l];
    i++;
    l++;
  }

  while (r < rightSub.size()) {
    arr[i] = rightSub[r];
    i++;
    r++;
  }
}

void mergesort(vector<int> &arr) {
  int length = arr.size();

  if (length <= 1)
    return; // base case

  int middle = length / 2;
  vector<int> leftSub, rightSub;

  // split the array into two parts
  for (size_t i = 0; i < length; i++) {
    if (i < middle) {
      leftSub.push_back(arr[i]);
    } else {
      rightSub.push_back(arr[i]);
    }
  }

  mergesort(leftSub);
  mergesort(rightSub);
  merge(leftSub, rightSub, arr);
}

int main() {
  vector<int> arr = {8, 2, 3, 7, 1, 3, 9, 6, 5};

  mergesort(arr);

  for (size_t i = 0; i < arr.size(); i++) {
    cout << arr[i] << ' ';
  }

  cout << '\n';
  return 0;
}