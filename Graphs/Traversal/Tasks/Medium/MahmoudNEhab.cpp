#include <cmath>
#include <iostream>
using namespace std;

int n;

int main() {
  cin >> n;
  int edges = n - 1;
  for (size_t i = 0; i < edges; i++) {
    int u, v;
    cin >> u >> v;
  }

  cout << floor((edges * edges)/4) - edges << endl;
  return 0;
}