#include <iostream>
#include <limits.h>
#include <queue>
#include <string>
#include <utility>
#include <vector>
#define INF INT_MAX
using namespace std;

/*The Bellman-Ford algorithm can handle directed and undirected graphs with non-negative weights.
 However, it can only handle directed graphs with negative weights, as long as we don't have negative cycles.*/

unsigned n, m;
vector<int> dist;
vector<string> par;

void print_dist() {
  for (size_t i = 1; i <= n; i++) {
    cout << "the dist to vertex " << i << " is: " << (-1) * dist[i] << '\n';
  }

  cout << '\n';
}

void print_par() {
  for (size_t i = 1; i <= n; i++) {
    cout << "the parent of vertex " << i << " is: " << par[i] << '\n';
  }

  cout << '\n';
}

void Bellman_Ford(const vector<vector<pair<int, int>>> &graph, int s) {
  dist[s] = 0;

  for (size_t i = 1; i <= n - 1; i++) {                             // |V| - 1 iterations needed
    for (size_t u = 1; u <= n; u++) {                               // for each vertex in the graph
      for (pair<int, int> v : graph[u]) {                           // for each outgoing edge (u,v)
        if (dist[u] != INF && dist[u] + v.second < dist[v.first]) { // skip the INF nodes && if we found a shorter dist => update
          dist[v.first] = dist[u] + v.second;
          par[v.first] = to_string(u);
        }
      }
    }
  }

  // if we update the values on the nth iteration then there is a negative cycle
  for (size_t u = 1; u <= n; u++) {
    for (pair<int, int> v : graph[u]) {
      if (dist[u] != INF && dist[u] + v.second < dist[v.first]) {
        cout << "Negative cycle!\n";
        return;
      }
    }
  }

  cout << "No negative cycles!\n";
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
    w = w * (-1);
    graph[u].push_back({v, w});
  }

  Bellman_Ford(graph, 1);
  print_dist();
  print_par();

  return 0;
}

/*
function bellmanFord(G, S)
  for each vertex V in G
    distance[V] <- infinite
    previous[V] <- NULL
  distance[S] <- 0

  for each vertex V in G
    for each edge (U,V) in G
      tempDistance <- distance[U] + edge_weight(U, V)
      if tempDistance < distance[V]
        distance[V] <- tempDistance
        previous[V] <- U

  for each edge (U,V) in G
    If distance[U] + edge_weight(U, V) < distance[V}
      Error: Negative Cycle Exists

  return distance[], previous[]
*/