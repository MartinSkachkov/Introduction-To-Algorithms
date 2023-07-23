#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>
using namespace std;

int n, m;
vector<bool> visited;

void traverse(const vector<vector<int>> &graph, int s) {
  if (visited[s] == true)
    return;

  visited[s] = true;
  cout << s << ' ';
  for (int v : graph[s]) {
    traverse(graph, v);
  }
}

void DFS(const vector<vector<int>> &graph) {
  visited.resize(n + 1, false);

  for (size_t i = 1; i <= n; i++) {
    if (visited[i] == false) {
      traverse(graph, i);
    }
  }

  cout << '\n';
}

int main() {
  cout << "# of vertices: ";
  cin >> n;

  cout << "# of edges: ";
  cin >> m;

  vector<vector<int>> graph(n + 1);
  int u, v;
  for (size_t i = 0; i < m; i++) {
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  DFS(graph);
  return 0;
}