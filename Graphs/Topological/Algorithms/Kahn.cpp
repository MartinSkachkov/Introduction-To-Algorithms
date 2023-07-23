#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int MAXN = 100;

int n, m;
vector<vector<int>> graph(MAXN);
vector<int> indegree(MAXN, 0);
vector<int> ordering;
bool isDag = true;

void Kahn() {
  // initialize the indegrees of each vertex
  for (size_t i = 0; i <= n; i++) {
    for (int u : graph[i]) { // outgoing edges if i
      indegree[u]++;
    }
  }

  // push the nodes of indegree zero to the queue
  queue<int> q;
  for (size_t i = 0; i <= n; i++) {
    if (indegree[i] == 0) {
      q.push(i);
    }
  }

  // update the ordering, in_degree, queue
  int index = 0;
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    ordering.push_back(v); // add the current vertex to the ordering
    index++;               // keep track of the added nodes

    // decrement the indegrees since we delete the node
    for (int u : graph[v]) {
      indegree[u]--;
      if (indegree[u] == 0) { // if one of them has become 0 after the decrementation add it to the queue
        q.push(u);
      }
    }
  }

  if (index != n) {
    cout << "graph is not a DAG\n";
    isDag = false;
    return;
  }
}

int main() {
  cin >> n >> m;

  for (size_t i = 0; i < m; i++) {
    int from, to;
    cin >> from >> to;
    graph[from].push_back(to);
  }

  Kahn();

  if (isDag) {
    for (int v : ordering) {
      cout << v << ' ';
    }
  }

  cout << endl;
  return 0;
}