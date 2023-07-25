#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>
using namespace std;
const int MAXN = 100;

int n, m, q;
vector<vector<pair<int, int>>> graph(MAXN);
vector<vector<int>> dist(MAXN, vector<int>(MAXN, INT_MAX));

void Warshall() {
  for (size_t i = 1; i <= n; i++) {
    dist[i][i] = 0;
  }

  for (size_t i = 1; i <= n; i++) {
    for (pair<int, int> v : graph[i]) {
      dist[i][v.first] = v.second;
    }
  }

  for (size_t k = 1; k <= n; k++) {
    for (size_t i = 1; i <= n; i++) {
      for (size_t j = 1; j <= n; j++) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
}

int main() {
  cin >> n >> m >> q;

  for (size_t i = 0; i < m; i++) {
    int city1, city2, cost;
    cin >> city1 >> city2 >> cost;
    graph[city1].push_back({city2, cost});
    graph[city2].push_back({city1, cost});
  }

  Warshall();

  for (size_t i = 0; i < q; i++) {
    int from, to;
    cin >> from >> to;
    cout << dist[from][to] << endl;
  }

  return 0;
}