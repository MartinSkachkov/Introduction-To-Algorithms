#include <iostream>
#include <vector>

class UnionFind {
private:
  std::vector<int> parent;
  std::vector<int> size;

public:
  UnionFind(int n) {
    parent.resize(n);
    size.resize(n, 1); // Initialize each component with a size of 1
    for (int i = 0; i < n; ++i) {
      parent[i] = i;
    }
  }

  int find(int x) {
    if (parent[x] != x) {
      parent[x] = find(parent[x]); // Path compression
    }
    return parent[x];
  }

  void unite(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    if (rootX == rootY) {
      return;
    }

    // Merge the smaller component into the larger one
    if (size[rootX] < size[rootY]) {
      parent[rootX] = rootY;
      size[rootY] += size[rootX];
    } else {
      parent[rootY] = rootX;
      size[rootX] += size[rootY];
    }
  }

  int componentSize(int x) {
    return size[find(x)];
  }
};

int main() {
  int n = 5; // Number of elements
  UnionFind uf(n);

  uf.unite(0, 2);
  uf.unite(1, 4);
  uf.unite(3, 2);

  std::cout << "Size of component containing 1: " << uf.componentSize(1) << std::endl;
  std::cout << "Size of component containing 0: " << uf.componentSize(0) << std::endl;

  return 0;
}
