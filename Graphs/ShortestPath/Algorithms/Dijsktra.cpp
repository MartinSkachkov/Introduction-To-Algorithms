#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <string>
#include <utility>
#include <vector>
#define INF INT_MAX
using namespace std;

unsigned n, m;
vector<int> dist;
vector<string> par;

void print_dist() {
  for (size_t i = 1; i <= n; i++) {
    cout << "shortest dist to " << i << " is: " << dist[i] << '\n';
  }
  cout << '\n';
}

void print_par() {
  for (size_t i = 1; i <= n; i++) {
    cout << "the parent of vertex " << i << " is: " << par[i] << '\n';
  }
  cout << '\n';
}

void print_path(int from, int to) {
  vector<int> path;
  path.push_back(to);

  while (from != to) {
    path.push_back(stoi(par[to]));
    to = stoi(par[to]);
  }

  reverse(path.begin(), path.end());

  for (int v : path) {
    cout << v << ' ';
  }
  cout << '\n';
}

void Dijkstra(const vector<vector<pair<int, int>>> &graph, int s) {
  dist[s] = 0;
  vector<bool> visited(n + 1, false);

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
        par[v.first] = to_string(u.second);                                         // save the parent of v to be u
        pq.push({dist[v.first], v.first});                                          // go with the next smallest one
      }
    }
  }
}

int main() {
  cout << "# of vertices: ";
  cin >> n;

  cout << "# of edges: ";
  cin >> m;

  vector<vector<pair<int, int>>> graph(n + 1);
  dist.resize(n + 1, INF);
  par.resize(n + 1, "nil");
  unsigned u, v, w;

  for (size_t i = 0; i < m; i++) {
    cin >> u >> v >> w;
    graph[u].push_back({v, w});
    graph[v].push_back({u, w});
  }

  cout << "strat vertex: ";
  unsigned s;
  cin >> s;

  Dijkstra(graph, s);
  print_dist();
  print_par();

  unsigned from, to;
  cout << "path from to: ";
  cin >> from >> to;
  print_path(from, to);

  return 0;
}