#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>
using namespace std;

vector<vector<pair<int, int>>> graph;
vector<int> dist;
vector<bool> visited;
vector<int> waitTime;
vector<int> par;

unsigned n, m;

void print_path(int s, int e) {
  vector<int> path;
  int count = 0;

  while (s != e) {
    path.push_back(e);
    e = par[e];
    count++;
  }

  reverse(path.begin(), path.end());
  cout << ++count << '\n';

  cout << s << ' ';
  for (int v : path) {
    cout << v << ' ';
  }
}

void dijkstra(int s, int e) {
  dist[s] = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({0, s});

  while (!pq.empty()) {
    pair<int, int> u = pq.top();
    pq.pop();
    visited[u.second] = true;

    for (pair<int, int> v : graph[u.second]) {
      if (visited[v.first] == false) {
        int new_dist = dist[u.second] + v.second;

        if (v.first != e) { // if we haven't reached the end vertex then consider the wait time for each adjacent stop and calculate it as a new distance
          new_dist = (new_dist / waitTime[v.first] + (new_dist % waitTime[v.first] != 0)) * waitTime[v.first];
        }

        if (new_dist < dist[v.first]) { // if we found a better dist which is smaller than the saved one update it and set the new parent
          dist[v.first] = new_dist;
          par[v.first] = u.second;
          pq.push({dist[v.first],v.first});
        }
      }
    }
  }
}

int main() {
  cin >> n >> m;

  graph.resize(n + 1);
  dist.resize(n + 1, INT_MAX);
  visited.resize(n + 1, false);
  waitTime.resize(n + 1, 0);
  par.resize(n + 1, -1);

  for (size_t i = 1; i <= n; i++) {
    cin >> waitTime[i];
  }

  unsigned from, to, w;
  for (size_t i = 0; i < m; i++) {
    cin >> from >> to >> w;
    graph[from].push_back({to, w});
  }

  dijkstra(1, n);
  cout << dist[n] << '\n';

  print_path(1, n);

  return 0;
}