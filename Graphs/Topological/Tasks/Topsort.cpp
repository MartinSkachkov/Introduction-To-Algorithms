#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int numCourses = 2;
vector<vector<int>> prerequisites = {
    {1, 0},
    {0, 1},
};

int main() {
  vector<vector<int>> graph(numCourses);
  for (int i = 0; i < prerequisites.size(); i++) {
    graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
  }

  vector<int> indegree(numCourses, 0);
  for (int i = 0; i < numCourses; i++) {
    for (int v : graph[i]) {
      indegree[v]++;
    }
  }

  queue<int> q;
  for (int i = 0; i < numCourses; i++) {
    if (indegree[i] == 0) {
      q.push(i);
    }
  }

  int index = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();

    index++;
    for (int v : graph[u]) {
      indegree[v]--;

      if (indegree[v] == 0) {
        q.push(v);
      }
    }
  }

  if (index != numCourses) {
    cout << "fasle";
  } else {
    cout << "true";
  }

  return 0;
}