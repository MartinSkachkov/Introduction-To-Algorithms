#include <iostream>
#include <vector>

class UnionFind {
private:
  std::vector<int> parent;
  std::vector<int> rank;

public:
  UnionFind(int n) {
    parent.resize(n);
    rank.resize(n, 0);
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

  void unite(int x, int y) { // union by rank based on depths
    int rootX = find(x);
    int rootY = find(y);

    if (rootX == rootY) {
      return;
    }

    if (rank[rootX] < rank[rootY]) {
      parent[rootX] = rootY;
    } else if (rank[rootX] > rank[rootY]) {
      parent[rootY] = rootX;
    } else {
      parent[rootY] = rootX;
      rank[rootX]++;
    }
  }
};

int main() {
  int n = 5; // Number of elements
  UnionFind uf(n);

  uf.unite(0, 2);
  uf.unite(1, 4);
  uf.unite(3, 2);

  std::cout << "Are 1 and 3 connected? " << (uf.find(1) == uf.find(3) ? "Yes" : "No") << std::endl;
  std::cout << "Are 0 and 4 connected? " << (uf.find(0) == uf.find(4) ? "Yes" : "No") << std::endl;

  return 0;
}
