#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>
using namespace std;
#define MAXN 10000

int n, mu, ms;

void Dijkstra(const vector<vector<pair<int, int>>> &graph, int s, vector<bool> &visited, vector<int> &dist) {
  dist[s] = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({0, s});

  while (!pq.empty()) {
    pair<int, int> u = pq.top();
    pq.pop();
    visited[u.second] = true;

    if (dist[u.second] < u.first)
      continue;                                                                     // if the distance in the array is better than the dist in the priority queue just continue, nothing to change
    for (pair<int, int> v : graph[u.second]) {                                      // for each adjacent vertex v of u
      if (visited[v.first] == false && dist[u.second] + v.second < dist[v.first]) { // if v is not visited and the dist from u to v is better than the one saved in the array for v
        dist[v.first] = dist[u.second] + v.second;                                  // update it to the shorter one
        pq.push({dist[v.first], v.first});                                          // go with the next smallest one
      }
    }
  }
}

int main() {
  cin >> n >> ms >> mu; // nodes, safe, unsafe

  vector<vector<pair<int, int>>> graph(n + 1);
  vector<bool> visited(MAXN, false);
  vector<int> dist(MAXN, INT_MAX);

  int u, v;
  for (size_t i = 0; i < ms; i++) {
    cin >> u >> v;
    graph[u].push_back({v, 0});
    graph[v].push_back({u, 0});
  }

  for (size_t i = 0; i < mu; i++) {
    cin >> u >> v;
    graph[u].push_back({v, 1});
    graph[v].push_back({u, 1});
  }

  Dijkstra(graph, 1, visited, dist);

  if (dist[n] == INT_MAX) {
    cout << -1 << endl;
  } else {
    cout << dist[n] << endl;
  }

  return 0;
}