#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
const int MAXN = 1e3 + 5;

int n, m;
vector<vector<int>> graph(MAXN);
vector<bool> visited(MAXN, false);

void dfs(int s) {
  if (visited[s] == true)
    return;

  visited[s] = true;

  for (int v : graph[s]) {
    dfs(v);
  }
}

int components() {
  int comp = 0;

  for (size_t i = 1; i <= n; i++) {
    if (visited[i] == false) {
      dfs(i);
      comp++;
    }
  }

  return comp;
}

int main() {
  cin >> n >> m;

  for (size_t i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  cout << components();

  cout << endl;
  return 0;
}