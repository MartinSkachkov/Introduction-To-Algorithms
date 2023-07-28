#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

int n, k, m;
vector<vector<int>> board;

vector<int> dirX = {2, 2, -2, -2, 1, 1, -1, -1};
vector<int> dirY = {1, -1, 1, -1, -2, 2, -2, 2};

bool valid(int x, int y) {
  return x >= 0 && x < n && y >= 0 && y < n && board[x][y] >= 0;
}

int main() {
  cin >> n >> m >> k;

  board.resize(n, vector<int>(n, 0));

  int hx, hy;
  for (size_t i = 0; i < m; i++) {
    cin >> hx >> hy;
    board[hx][hy] = -1;
  }

  int kx, ky;
  for (size_t i = 0; i < k; i++) {
    cin >> kx >> ky;
    board[kx][ky] = 1;
  }

  int px, py;
  cin >> px >> py;
  board[px][py] = -1; // mark the princess as hole

  queue<pair<int, int>> q;
  q.push({px, py});

  int currDist = 0, resDist = 0, cntK = 0, rem = 1; // rem will tell us how many elements are left in the queue

  while (!q.empty()) {
    pair<int, int> cord = q.front();
    q.pop();
    rem--;

    for (size_t i = 0; i < 8; i++) { // check if we can go to all sides
      int newX = cord.first + dirX[i];
      int newY = cord.second + dirY[i];

      if (valid(newX, newY)) {   // if the new coordinates are valid (a.k.a we can step there)
        if (board[newX][newY]) { // and if we stepped on a knight
          cntK++;
          resDist = currDist + 1;
        }

        // otherwise mark it as visited(a.k.a hole so that we don't repeat it in the future)
        board[newX][newY] = -1;
        q.push({newX, newY}); // see from the new coordinates to where we can go
      }
    }

    if (rem == 0) {
      rem = q.size();
      currDist++;
    }
  }

  cout << cntK << ' ' << resDist << endl;
  return 0;
}