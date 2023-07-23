#include <iostream>
using namespace std;

void change(int arr[]) {
  for (int i = 0; i < 3; i++) {
    arr[i] = 4;
  }

  int x = 5;
  arr = &x;
}

int main() {
  int arr[3] = {1, 2, 3};
  change(arr);
  for (int i = 0; i < 3; i++) {
    cout << arr[i];
  }

  return 0;
}