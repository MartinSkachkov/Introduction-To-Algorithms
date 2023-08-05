#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Edge {
  int src, dest, weight;
};

class UnionFind {
public:
  UnionFind(int n) : parent(n), rank(n, 0) {
    for (int i = 0; i < n; ++i)
      parent[i] = i;
  }

  int find(int x) {
    if (parent[x] != x)
      parent[x] = find(parent[x]);
    return parent[x];
  }

  void unite(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY) {
      if (rank[rootX] > rank[rootY])
        parent[rootY] = rootX;
      else {
        parent[rootX] = rootY;
        if (rank[rootX] == rank[rootY])
          rank[rootY]++;
      }
    }
  }

private:
  vector<int> parent, rank;
};

bool compareEdges(const Edge &a, const Edge &b) {
  return a.weight < b.weight;
}

vector<Edge> kruskalMST(vector<Edge> &edges, int numVertices) {
  sort(edges.begin(), edges.end(), compareEdges);
  UnionFind uf(numVertices);
  vector<Edge> result;

  for (const Edge &edge : edges) {
    int srcRoot = uf.find(edge.src);
    int destRoot = uf.find(edge.dest);

    if (srcRoot != destRoot) {
      result.push_back(edge);
      uf.unite(srcRoot, destRoot);
    }
  }

  return result;
}

int main() {
  int numVertices, numEdges;
  cin >> numVertices >> numEdges;

  vector<Edge> edges(numEdges);
  for (int i = 0; i < numEdges; ++i) {
    cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
  }

  vector<Edge> mst = kruskalMST(edges, numVertices);

  cout << "Minimum Spanning Tree Edges:" << endl;
  for (const Edge &edge : mst) {
    cout << edge.src << " - " << edge.dest << " : " << edge.weight << endl;
  }

  return 0;
}
