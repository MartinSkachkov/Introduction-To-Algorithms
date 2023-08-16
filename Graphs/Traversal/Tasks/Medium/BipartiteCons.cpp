#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1000; // Максимален брой софтуеристи

vector<int> graph[MAXN];
bool visited[MAXN];
bool color[MAXN];

bool isBipartiteDFS(int u, int n1, int n2, int &cntDevelopers, int &cntTesters) {
  visited[u] = true;
  if (color[u]) {
    cntDevelopers++;
  } else {
    cntTesters++;
  }

  for (int v : graph[u]) {
    if (!visited[v]) {
      color[v] = !color[u];
      isBipartiteDFS(v, n1, n2, cntDevelopers, cntTesters);
    } else if (color[v] == color[u]) {
      return false;
    }
  }

  return true;
}

bool isPossibleToArrange(int n, int n1, int n2, vector<int> cubicleNeighbors[]) {
  for (int i = 0; i < n; ++i) {
    graph[i].clear();
    visited[i] = false;
  }

  for (int i = 0; i < n; ++i) {
    for (int j : cubicleNeighbors[i]) {
      graph[i].push_back(j);
      graph[j].push_back(i);
    }
  }

  for (int i = 0; i < n; ++i) {
    if (!visited[i]) {
      int cntDevelopers = 0, cntTesters = 0;
      if (!isBipartiteDFS(i, n1, n2, cntDevelopers, cntTesters) ||
          cntDevelopers < n1 || cntTesters < n2) {
        return false;
      }
    }
  }

  return true;
}

int main() {
  int n, n1, n2;
  cin >> n >> n1 >> n2;

  vector<int> cubicleNeighbors[n];

  for (int i = 0; i < n; ++i) {
    int numNeighbors;
    cin >> numNeighbors;

    for (int j = 0; j < numNeighbors; ++j) {
      int neighbor;
      cin >> neighbor;
      cubicleNeighbors[i].push_back(neighbor);
    }
  }

  if (isPossibleToArrange(n, n1, n2, cubicleNeighbors)) {
    cout << "TRUE" << endl;
  } else {
    cout << "FALSE" << endl;
  }

  return 0;
}