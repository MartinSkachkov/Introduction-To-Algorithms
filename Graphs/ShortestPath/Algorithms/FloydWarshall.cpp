#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;
#define INF (INT_MAX / 2)

vector<vector<pair<int, int>>> graph;
vector<vector<int>> dist;
unsigned n, m;

void Floyd_Warshall() {
  for (size_t v = 1; v <= n; v++) {
    dist[v][v] = 0;
  }

  for (size_t u = 1; u <= n; u++) {
    for (pair<int, int> v : graph[u]) {
      dist[u][v.first] = v.second;
    }
  }

  for (size_t k = 1; k <= n; k++) {
    for (size_t i = 1; i <= n; i++) {
      for (size_t j = 1; j <= n; j++) {
        if (dist[i][j] > dist[i][k] + dist[k][j]) {
          dist[i][j] = dist[i][k] + dist[k][j];
        }
      }
    }
  }
}

int main() {
  cin >> n >> m;

  graph.resize(n + 1);
  unsigned from, to, w;
  for (size_t i = 0; i < m; i++) {
    cin >> from >> to >> w;
    graph[from].push_back({to, w});
  }

  dist.resize(n + 1, vector<int>(n + 1, INF));

  Floyd_Warshall();

  for (size_t u = 1; u <= n; u++) {
    for (size_t v = 1; v <= n; v++) {
      cout << "from: " << u << " to: " << v << " weight: " << dist[u][v] << '\n';
    }
  }

  return 0;
}