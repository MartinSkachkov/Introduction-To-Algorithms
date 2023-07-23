#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
const int MAXN = 1e3 + 5;

int n, m, q;
vector<vector<int>> graph(MAXN);
vector<int> visited(MAXN, false);
vector<int> comp(MAXN);

void bfs(int s, int compId) {
  visited[s] = true;
  queue<int> q;
  q.push(s);

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    for (int v : graph[u]) {
      if (visited[v] == false) {
        visited[v] = true;
        comp[v] = compId;
        q.push(v);
      }
    }
  }
}

void initialize_comp() {
  int compId = 0;

  for (size_t i = 1; i <= n; i++) {
    if (visited[i] == false) {
      bfs(i, compId);
      compId++;
    }
  }
}

int main() {
  cin >> n >> m;

  for (size_t i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  initialize_comp();
  cin >> q;
  vector<int> res;

  for (size_t i = 0; i < q; i++) {
    int from, to;
    cin >> from >> to;
    if (comp[from] == comp[to]) {
      res.push_back(1);
    } else {
      res.push_back(0);
    }
  }

  for (int x : res) {
    cout << x;
  }

  cout << endl;
  return 0;
}