#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
const int MAXN = 1e3 + 5;

int n, m, k;
int grid[MAXN][MAXN] = {0};
vector<vector<int>> graph(MAXN);
vector<bool> visited(MAXN, false);

int coord_to_int(int x, int y) {
  return m * x + y;
}

void dfs(int s) {
  if (visited[s] == true) {
    return;
  }

  visited[s] = true;

  for (int v : graph[s]) {
    dfs(v);
  }
}

int components() {
  int comp = 0;

  for (size_t i = 1; i <= n; i++) {
    for (size_t j = 1; j <= m; j++) {
      if (visited[coord_to_int(i, j)] == false && !grid[i][j]) {
        dfs(coord_to_int(i, j));
        comp++;
      }
    }
  }

  return comp;
}

void grid_to_graph() {
  for (size_t i = 1; i <= m; i++) {
    for (size_t j = 0; j <= m; j++) {
      if (!grid[i][j]) {
        if (i + 1 <= n) {
          graph[coord_to_int(i, j)].push_back(coord_to_int(i + 1, j));
        }
        if (j + 1 <= m) {
          graph[coord_to_int(i, j)].push_back(coord_to_int(i, j + 1));
        }
        if (i - 1 >= 1) {
          graph[coord_to_int(i, j)].push_back(coord_to_int(i - 1, j));
        }
        if (j - 1 >= 1) {
          graph[coord_to_int(i, j)].push_back(coord_to_int(i, j - 1));
        }
      }
    }
  }
}

int main() {
  cin >> n >> m >> k;

  for (size_t i = 0; i < k; i++) {
    int x, y;
    cin >> x >> y;
    grid[x][y] = 1;
  }

  grid_to_graph();
  cout << components();

  cout << endl;
  return 0;
}