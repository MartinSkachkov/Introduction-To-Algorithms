#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &arr, int start, int end) {
  int pivot = arr[end];
  int i = start - 1;

  for (int j = start; j < end; j++) {
    if (arr[j] < pivot) {
      i++;
      swap(arr[j], arr[i]);
    }
  }

  i++;
  swap(arr[i], arr[end]);
  return i;
}

void quickSort(vector<int> &arr, int start, int end) {
  if (end <= start) {
    return;
  }

  int pivot = partition(arr, start, end);
  quickSort(arr, start, pivot - 1);
  quickSort(arr, pivot + 1, end);
}

int main() {

  // vector<int> arr = {8, 2, 3, 7, 1, 3, 9, 6, 5};
  vector<int> arr;
  int n, num;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> num;
    arr.push_back(num);
  }

  quickSort(arr, 0, arr.size() - 1);

  for (int elem : arr) {
    cout << elem << ' ';
  }

  return 0;
}