#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>
using namespace std;

vector<vector<pair<int, int>>> graph;
vector<int> floors;
vector<int> dist;
vector<bool> visited;

void dijkstra(int s) {
  dist[s] = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({s, 0});

  while (!pq.empty()) {
    pair<int, int> u = pq.top();
    pq.pop();
    visited[u.first] = true;

    if (dist[u.first] < u.second) {
      continue;
    }

    for (pair<int, int> v : graph[u.first]) {
      if (visited[v.first] == false && dist[u.first] + v.second < dist[v.first]) {
        dist[v.first] = dist[u.first] + v.second;
        pq.push({v.first, dist[v.first]});
      }
    }
  }
}

int main() {
  int n, u, d, I, J, l;
  cin >> n >> u >> d >> I >> J >> l;

  graph.resize(n + 1);
  dist.resize(n + 1, INT_MAX);
  visited.resize(n + 1, false);

  for (size_t i = 2; i <= n; i++) {
    graph[i - 1].emplace_back(i, u); // add edge for the upper floor
    graph[i].emplace_back(i - 1, d); // add edge for the bottom floor
  }

  // for each lift set where it stops
  for (size_t i = 0; i < l; i++) {
    int k; // number of stops
    cin >> k;

    // for each stop set the floor
    int f;
    for (size_t s = 0; s < k; s++) {
      cin >> f;
      floors.push_back(f);

      for (size_t j = 0; j < s; j++) {
        graph[floors[j]].emplace_back(floors[s], I + J);
        graph[floors[s]].emplace_back(floors[j], I + J);
      }
    }
  }

  dijkstra(1);
  cout << dist[n];

  return 0;
}