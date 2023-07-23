#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
const int MAXN = 1e3 + 5;

vector<vector<pair<int, int>>> graph(MAXN);
vector<bool> visited(MAXN, false);
int n, m, k;

void dfs(int s) {
  visited[s] = true;

  for (pair<int, int> node : graph[s]) {
    if (visited[node.first] == false && node.second >= k) {
      dfs(node.first);
    }
  }
}

int main() {
  cin >> n >> m;

  for (size_t i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    graph[u].push_back({v, w});
    graph[v].push_back({u, w});
  }

  cin >> k;

  int ans = 0;
  for (size_t i = 1; i <= n; i++) {
    if (visited[i] == false) {
      dfs(i);
      ans++;
    }
  }

  cout << ans - 1 << endl;
  return 0;
}