#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>
using namespace std;
const int MAXN = 100;

int n, start, finish;
vector<vector<pair<int, int>>> graph(MAXN);
vector<int> dist(MAXN, INT_MAX);
vector<bool> visited(MAXN, false);

void Dijkstra() {
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({0, start});
  dist[start] = 0;

  while (!pq.empty()) {
    pair<int, int> curr = pq.top();
    pq.pop();
    visited[curr.second] = true;

    if (dist[curr.second] < curr.first) {
      continue;
    }
    for (pair<int, int> v : graph[curr.second]) {
      if (visited[v.first] == false && dist[curr.second] + v.second < dist[v.first]) {
        dist[v.first] = dist[curr.second] + v.second;
        pq.push({dist[v.first], v.first});
      }
    }
  }
}

int main() {
  cin >> n >> start >> finish;

  int from, to;
  while (cin >> from >> to) {
    graph[from].push_back({to, 0}); // we don't care about the legal moves so we don't count them
    graph[to].push_back({from, 1}); // we care about the number of illegal ones so we track them
  }

  Dijkstra();

  if (dist[finish] == INT_MAX) {
    cout << 'x' << endl;
  } else {
    cout << dist[finish] << endl;
  }

  return 0;
}