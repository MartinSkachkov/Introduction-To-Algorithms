#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Интуитивна аргументация на коректността на алгоритъма е, че най-малката f-стойност задължително е на сифон

unsigned n, m;
vector<string> color;
vector<string> par;

int time, l;
vector<int> d, f, t; // discovery time of vertex, finalizing time of vertex, Toposort ordering

void DFS_MOD(const vector<vector<int>> &graph, int s) {
  color[s] = "gray";
  time++;
  d[s] = time;

  for (int v : graph[s]) {
    if (color[v] == "white") {
      par[v] = to_string(s);
      DFS_MOD(graph, v);
    }
  }

  color[s] = "black";
  time++;
  f[s] = time;
  t[l] = s;
  l--;
}

void Tarjan(const vector<vector<int>> &graph) {
  // not necessary since we used the vector constructor but left to be a complete implementation
  for (size_t i = 1; i <= n; i++) {
    color[i] = "white";
    par[i] = "nil";
  }

  time = 0, l = n;
  for (size_t i = 1; i <= n; i++) {
    if (color[i] == "white") {
      DFS_MOD(graph, i);
    }
  }

  // return T;
}

int main() {
  cout << "# of vertices: ";
  cin >> n;

  cout << "# of edges: ";
  cin >> m;

  // graph
  vector<vector<int>> graph(n + 1); // 1-indexed
  color.resize(n + 1, "white");
  par.resize(n + 1, "nil");
  int u, v;

  for (size_t i = 0; i < m; i++) {
    cin >> u >> v;
    graph[u].push_back(v);
  }

  t.resize(n + 1);
  d.resize(n + 1);
  f.resize(n + 1);

  Tarjan(graph);
  cout << "Tarjan toposort\n";
  for (size_t i = 1; i <= n; i++) {
    cout << t[i] << ' ';
  }

  return 0;
}