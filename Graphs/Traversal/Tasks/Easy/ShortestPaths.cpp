#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m;

void bfs(const vector<vector<int>> &graph, vector<int> &dist, int start) {
  vector<bool> visited(n + 1);
  visited[start] = true;
  dist[start] = 0;
  queue<int> q;
  q.push(start);

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    for (int v : graph[u]) {
      if (visited[v] == false) {
        visited[v] = true;
        dist[v] = dist[u] + 1;
        q.push(v);
      }
    }
  }
}

int main() {
  cin >> n >> m;

  vector<vector<int>> graph(n + 1);
  vector<int> dist(n + 1, -1);
  int u, v;
  for (size_t i = 0; i < m; i++) {
    cin >> u >> v;
    graph[u].push_back(v);
  }

  int start;
  cin >> start;
  bfs(graph, dist, start);
  for (size_t i = 1; i <= n; i++) {
    cout << dist[i] << ' ';
  }

  cout << endl;
  return 0;
}