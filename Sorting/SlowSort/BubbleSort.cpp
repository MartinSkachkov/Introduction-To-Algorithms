#include <iostream>
using namespace std;

int main() {
  int n = 6;
  int arr[n] = {19, 25, 32, 48, 53, 56};

  for (size_t i = 0; i <= n - 1; i++) {
    for (size_t j = 0; j <= n - 1 - i; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
      }
    }
  }

  for (size_t i = 0; i < n; i++) {
    cout << arr[i] << ' ';
  }

  cout << '\n';
  return 0;
}