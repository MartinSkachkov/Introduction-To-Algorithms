#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
vector<int> par;
unsigned n, m;

void dfs(int s, bool &ans) {
  visited[s] = true;

  for (int v : graph[s]) {
    if (visited[v] == false) {
      par[v] = s;
      dfs(v, ans);
    } else if (par[s] != v) {
      ans = true;
      break;
    }
  }
}

bool hasCycle() {
  bool ans = false;

  for (size_t i = 1; i <= n; i++) {
    if (visited[i] == false) {
      dfs(i, ans);
    }
  }

  return ans;
}

int main() {
  cin >> n >> m;

  graph.resize(n + 1);
  visited.resize(n + 1, false);
  par.resize(n + 1, INT_MIN);

  unsigned u, v;
  for (size_t i = 0; i < m; i++) {
    cin >> u >> v;
    graph[u].push_back(v);
    //   graph[v].push_back(u);
  }

  cout << hasCycle();

  return 0;
}