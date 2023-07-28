#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

const int MAXN = 1000000;

int n, ti, mi, node, execTime[MAXN] = {0}, prv[MAXN] = {0}, totalTime[MAXN] = {0};
vector<vector<int>> graph(MAXN);

int main() {
  cin >> n;

  // for each task starting from 0
  for (size_t i = 0; i < n; i++) {
    cin >> execTime[i];
    cin >> mi;
    prv[i] = mi;

    for (size_t j = 0; j < mi; j++) {
      cin >> node;
      graph[node].push_back(i);
    }
  }

  queue<int> q;
  for (size_t i = 0; i < n; i++) {
    // if there is a task that doesn't need others to be done before it add it to the queue as starting point
    if (prv[i] == 0) {
      q.push(i);
      totalTime[i] = execTime[i]; // therefore we know it't total time since we start from that task
    }
  }

  while (!q.empty()) {
    int currTask = q.front();
    q.pop();

    for (int v : graph[currTask]) {
      prv[v]--;
      totalTime[v] = max(totalTime[v], totalTime[currTask] + execTime[v]);
      if (prv[0] == 0) {
        q.push(v); // next starting node
      }
    }
  }

  for (int i = 0; i < n; i++)
    cout << totalTime[i] << '\n';
  return 0;
}