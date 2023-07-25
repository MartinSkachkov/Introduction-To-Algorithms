#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>
#define INF INT_MAX
using namespace std;

const int MAXN = 100;

int n, m, k, x, y, t, d, q, hotel;
vector<vector<pair<int, int>>> graph(MAXN);
vector<int> dest;
vector<int> dist(MAXN, INF);
vector<bool> visited(MAXN, false);

int findMinDist() {
  int min = INT_MAX;

  for (int landmark : dest) {
    int currDist = dist[landmark];
    if (currDist < min) {
      min = currDist;
    }
  }

  return min;
}

void dijkstra(int start) {
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({0, start});
  dist[start] = 0;

  while (!pq.empty()) {
    pair<int, int> v = pq.top();
    pq.pop();
    visited[v.second] = true;

    if (dist[v.second] < v.first) {
      continue;
    }
    for (pair<int, int> u : graph[v.second]) {
      if (visited[u.first] == false && dist[v.second] + u.second < dist[u.first]) {
        dist[u.first] = dist[v.second] + u.second;
        pq.push({dist[u.first], u.first});
      }
    }
  }
}

int main() {
  cin >> n >> m;

  for (size_t i = 0; i < m; i++) {
    cin >> x >> y >> t;
    graph[x].push_back({y, t});
    graph[y].push_back({x, t});
  }

  cin >> k;
  for (size_t i = 0; i < k; i++) {
    cin >> d;
    dest.push_back(d);
  }

  cin >> q;
  for (size_t i = 0; i < q; i++) {
    cin >> hotel;
    fill(visited.begin(), visited.end(), false);
    fill(dist.begin(), dist.end(), INF);

    dijkstra(hotel);

    cout << findMinDist() << endl;
  }

  return 0;
}