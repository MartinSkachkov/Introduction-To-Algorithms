#include <iostream>
using namespace std;

int main() {
  int n = 6, j;
  int arr[n] = {19, 25, 32, 48, 53, 56};

  for (size_t i = 1; i <= n - 1; i++) {
    j = i;
    while (j > 0 && arr[j - 1] > arr[j]) {
      swap(arr[j - 1], arr[j]);
      j--;
    }
  }

  for (size_t i = 0; i < n; i++) {
    cout << arr[i] << ' ';
  }

  cout << '\n';
  return 0;
}