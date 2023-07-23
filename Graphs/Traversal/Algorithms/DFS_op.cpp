#include <iostream>
#include <string>
#include <vector>
using namespace std;

unsigned n, m;
vector<string> color;
vector<string> par;
vector<int> d, f;
int time;

void DFS(const vector<vector<int>> &graph, int s) {
    color[s] = "gray";
    time++;
    d[s] = time;

    for (int v : graph[s]) {
        if (color[v] == "white") {
            par[v] = to_string(s);
            DFS(graph, v);
        }
    }

    color[s] = "black";
    time++;
    f[s] = time;
}

void DFS_MOD(const vector<vector<int>> &graph) {
    // this for is not necessary since we used the vector constructor
    for (size_t i = 1; i <= n; i++) {
        color[i] = "white";
        par[i] = "nil";
    }

    time = 0;
    for (size_t i = 1; i <= n; i++) {
        if (color[i] == "white") {
            DFS(graph, i);
        }
    }
}

int main() {
    cout << "# of vertices: ";
    cin >> n;

    cout << "# of edges: ";
    cin >> m;

    vector<vector<int>> graph(n + 1);
    color.resize(n + 1, "white");
    par.resize(n + 1, "nil");
    d.resize(n + 1, 0);
    f.resize(n + 1, 0);
    int u, v;

    for (size_t i = 0; i < m; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    DFS_MOD(graph);

    for (size_t i = 1; i <= n; i++) {
        cout << "parent of " << i << " is: " << par[i] << '\n';
    }

    for (size_t i = 1; i <= n; i++) {
        cout << "time of finding " << i << " is: " << d[i] << '\n';
    }

    for (size_t i = 1; i <= n; i++) {
        cout << "time of finalizng " << i << " is: " << f[i] << '\n';
    }

    return 0;
}