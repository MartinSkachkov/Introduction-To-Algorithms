#include <iostream>
using namespace std;

int main() {
  int n = 7, currMinId;
  int arr[7] = {2, 8, 5, 3, 9, 4, 1};

  for (size_t i = 0; i < n - 1; i++) {
    currMinId = i;
    for (size_t j = i + 1; j < n; j++) {
      if (arr[j] < arr[currMinId]) {
        currMinId = j;
      }
    }

    swap(arr[currMinId], arr[i]);
  }

  for (size_t i = 0; i < n; i++) {
    cout << arr[i] << ' ';
  }

  cout << '\n';
  return 0;
}