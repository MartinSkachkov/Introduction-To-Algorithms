#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
const int MAXN = 1e3 + 5;

int n, m;
vector<vector<int>> graph(MAXN);
vector<bool> visited(MAXN);
vector<bool> color(MAXN, 0);

void dfs(int s, bool &ans) {
  visited[s] = true;

  for (int v : graph[s]) {
    if (visited[v] == false) {
      color[v] = !color[s];
      dfs(v, ans);
    } else if (color[s] == color[v]) {
      ans = false;
      return;
    }
  }
}

bool isBipartite() {
  bool ans = true;

  for (size_t i = 0; i < n; i++) {
    if (visited[i] == false) {
      dfs(i, ans);
    }
  }

  return ans;
}

int main() {
  cin >> n >> m;

  for (size_t i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  bool ans = true;
  cout << boolalpha << isBipartite();

  cout << endl;
  return 0;
}