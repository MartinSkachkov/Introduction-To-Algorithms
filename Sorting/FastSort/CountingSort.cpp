#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

void print(const vector<int> &arr) {
  for (int el : arr) {
    cout << el << ' ';
  }
  cout << '\n';
}

vector<int> countingSort(const vector<int> &arr, int k) {
  vector<int> occurs(k); // create new arr of size k(range) which will store the number of occurrances of each number
  for (int el : arr) {
    occurs[el]++;
  }

  cout << "Occurrance array:\n";
  print(occurs);

  // now perform the sum
  for (size_t i = 1; i < k; i++) {
    occurs[i] += occurs[i - 1];
  }

  cout << "Summed array:\n";
  print(occurs);

  // now perform the right shift - the value in the array shows from which index to start each number
  for (size_t i = k - 1; i > 0; i--) {
    occurs[i] = occurs[i - 1];
  }
  occurs[0] = 0;

  cout << "Shifted array:\n";
  print(occurs);

  // saving the result
  vector<int> res(arr.size());
  int place;
  for (int el : arr) {
    place = occurs[el];
    res[place] = el;
    occurs[el]++; // update the placement index for the next element
  }

  return res;
}

int findMax(const vector<int> &arr) {
  int max = arr[0];
  for (size_t i = 1; i < arr.size(); i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }

  return max;
}

// works only with non-negative numbers
int main() {
  vector<int> arr = {4, 2, 2, 8, 3, 3, 1};
  int k = findMax(arr); // range of values in the arr
  k++;                  // since we include zero
  cout << "k: " << k << endl;
  vector<int> res = countingSort(arr, k);

  cout << "Res arr:\n";
  print(res);

  cout << '\n';
  return 0;
}