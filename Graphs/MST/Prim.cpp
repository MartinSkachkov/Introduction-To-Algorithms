#include <iostream>
#include <queue>
using namespace std;
const int MAXN = 1000;

int n, m;
vector<vector<pair<int, int>>> graph(MAXN);
vector<int> mst;
vector<bool> visited(MAXN, false);
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void addEdges(int node) {
  visited[node] = true;

  // add all outgoing edges to the queue
  for (pair<int, int> outgEdge : graph[node]) {
    if (!visited[outgEdge.second]) {
      pq.push(outgEdge);
    }
  }
}

int Prim(int s) {
  int expectedEdgeCount = n - 1;
  int edgeCount = 0, mstCost = 0;

  addEdges(s);
  mst.push_back(s);

  while (!pq.empty() && expectedEdgeCount != edgeCount) {
    pair<int, int> currNode = pq.top();
    pq.pop();

    if (visited[currNode.second]) {
      continue;
    }

    // it's a good edge
    edgeCount++;
    mstCost += currNode.first;
    mst.push_back(currNode.second);

    addEdges(currNode.second);
  }

  if (edgeCount != expectedEdgeCount) {
    cout << "no mst!";
    return 0;
  }

  return mstCost;
}

int main() {
  cin >> n >> m;

  int u, v, w;
  for (size_t i = 0; i < m; i++) {
    cin >> u >> v >> w;
    graph[u].push_back({w, v});
    graph[v].push_back({w, u});
  }

  int startNode;
  cin >> startNode;
  cout << Prim(startNode) << endl;

  for (int v : mst) {
    cout << v << ' ';
  }
  cout << endl;
  
  return 0;
}