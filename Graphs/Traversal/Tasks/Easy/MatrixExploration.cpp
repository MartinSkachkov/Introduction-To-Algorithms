#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
const int MAXN = 1e3 + 5;

int n, m, k;
char grid[MAXN][MAXN];
queue<pair<int, int>> q;
vector<vector<bool>> visited(MAXN, vector<bool>(MAXN, false));
vector<vector<int>> dist(MAXN, vector<int>(MAXN, -1));
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool inGrid(int x, int y) {
  return (x >= 1 && x <= n && y >= 1 && y <= m);
}

void bfs() {
  while (!q.empty()) {
    pair<int, int> currNode = q.front();
    q.pop();

    for (size_t i = 0; i < 4; i++) { // check 4 coordinates
      int x = currNode.first + dx[i];
      int y = currNode.second + dy[i];

      if (!inGrid(x, y) || visited[x][y] == true || grid[x][y] == '#')
        continue;
      int length = dist[currNode.first][currNode.second] + 1;
      if (dist[x][y] == -1)
        dist[x][y] = length;
      else
        dist[x][y] = min(dist[x][y], length);
      q.push({x, y});
      visited[x][y] = true;
    }
  }
}

int computeDist() {
  int ans = 0;

  for (size_t i = 1; i <= n; i++)
    for (size_t j = 1; j <= m; j++)
      if (grid[i][j] == '.')
        ans += dist[i][j];

  return ans;
}

int main() {
  cin >> n >> m >> k;
  for (size_t i = 1; i <= n; i++) {
    for (size_t j = 1; j <= m; j++) {
      cin >> grid[i][j];
    }
  }

  for (size_t i = 0; i < k; i++) {
    int x, y;
    cin >> x >> y;
    dist[x][y] = 0;
    q.push({x, y});
  }

  bfs();
  cout << computeDist() << endl;

  return 0;
}
