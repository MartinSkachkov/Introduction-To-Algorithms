#include <iostream>
#include <stack>
#include <vector>
using namespace std;
const int MAXN = 100;

int n, m, cmpCnt;
vector<vector<int>> graph(MAXN);
vector<bool> visited(MAXN, false);
vector<int> comp;

vector<vector<int>> transposeGraph(vector<vector<int>> graph) {
  vector<vector<int>> transposed(MAXN);

  for (size_t i = 0; i <= n; i++) {
    for (int v : graph[i]) {
      transposed[v].push_back(i);
    }
  }

  return transposed;
}

void dfs1(int i, stack<int> &s) {
  visited[i] = true;

  for (int v : graph[i]) {
    if (visited[v] == false) {
      dfs1(v, s);
    }
  }

  s.push(i);
}

void dfs2(const vector<vector<int>> &graph, int s, int cmpCnt) {
  visited[s] = true;
  comp[s] = cmpCnt;

  for (int v : graph[s]) {
    if (visited[v] == false) {
      dfs2(graph, v, cmpCnt);
    }
  }
}

void SCC() {
  comp.resize(n + 1, -1);
  cmpCnt = 0;
  stack<int> s;

  // fill the stack
  for (size_t i = 0; i <= n; i++) {
    if (visited[i] == false) {
      dfs1(i, s);
    }
  }

  // reverse the graph
  vector<vector<int>> transposed = transposeGraph(graph);

  // initialize comp
  fill(visited.begin(), visited.end(), false);
  while (!s.empty()) {
    int v = s.top();
    s.pop();

    if (visited[v] == false) {
      dfs2(transposed, v, cmpCnt);
      cmpCnt++;
    }
  }
}

int main() {
  cin >> n >> m;

  for (size_t i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
  }

  SCC();

  for (size_t i = 0; i < cmpCnt; i++) {
    cout << "component " << i + 1 << endl;

    for (size_t j = 0; j < comp.size(); j++) {
      if (comp[j] == i) {
        cout << j << ' ';
      }
    }

    cout << endl;
  }

  cout << endl;
  return 0;
}