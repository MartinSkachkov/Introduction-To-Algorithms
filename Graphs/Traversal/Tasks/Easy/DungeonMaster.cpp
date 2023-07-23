#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
const int MAXN = 1e3 + 5;

int n, m, ex, ey, sx, sy;
char grid[MAXN][MAXN];
vector<vector<int>> dist(MAXN, vector<int>(MAXN, -1));
vector<vector<bool>> visited(MAXN, vector<bool>(MAXN, false));
queue<pair<int, int>> q;
int dx[4] = {-1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool inBounds(int x, int y) {
  return (x >= 1 && x <= n && y >= 1 && y <= m);
}

int bfs() {
  while (!q.empty()) {
    pair<int, int> currNode = q.front();
    q.pop();

    // check neighbours
    for (size_t i = 0; i < 4; i++) {
      int x = currNode.first + dx[i];
      int y = currNode.second + dy[i];

      if (!inBounds(x, y) || visited[x][y] == true || grid[x][y] == '#') {
        continue;
      }

      int length = dist[currNode.first][currNode.second] + 1;
      if (dist[x][y] == -1) {
        dist[x][y] = length;
      } else {
        dist[x][y] = min(length, dist[x][y]);
      }

      q.push({x, y});
      visited[x][y] = true;
    }
  }

  if (dist[ex][ey] == -1) {
    cout << "Trapped\n";
    return -1;
  } else {
    return dist[ex][ey];
  }
}

int main() {
  cin >> n >> m;

  for (size_t i = 1; i <= n; i++) {
    for (size_t j = 1; j <= m; j++) {
      cin >> grid[i][j];
    }
  }

  cin >> sx >> sy >> ex >> ey;
  dist[sx][sy] = 0;
  q.push({sx, sy});

  cout << bfs() << endl;

  return 0;
}