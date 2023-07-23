#include <iostream>
#include <queue>
#include <limits.h>
#include <vector>
using namespace std;

unsigned n, m;
vector<string> color;
vector<int> dist;
vector<int> par;

void print_graph(const vector<vector<int>> &graph) {
    cout << "Our graph\n";

    for (size_t u = 0; u < graph.size(); u++) {
        if (!graph[u].empty()) {
            cout << "neightbours of vertex " << u << " : ";
            for (int v : graph[u]) {
                cout << v << ' ';
            }

            cout << '\n';
        }
    }

    cout << '\n';
}

void print_dist(const vector<vector<int>> &graph) {
    for (size_t i = 1; i <= n; i++) {
        cout << "distance to vertex " << i << " is: " << dist[i] << '\n';
    }

    cout << '\n';
}

void print_par(const vector<vector<int>> &graph) {
    for (size_t i = 1; i <= n; i++) {
        cout << "parent of vertex " << i << " is: " << par[i] << '\n';
    }

    cout << '\n';
}

void BFS(const vector<vector<int>> &graph, int s) {
    color[s] = "gray";
    queue<int> q;
    q.push(s);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u;

        for (int v : graph[u]) {
            if (color[v] == "white") {
                color[v] = "gray";
                q.push(v);
                dist[v] = dist[u] + 1;
                par[v] = u;
            }
        }

        color[u] = "black";
    }
}

int BFS_MOD(const vector<vector<int>> &graph) {
    // this for is not necessary since we initialized the vectors when we declared them
    for (size_t i = 1; i <= n; i++) {
        color[i] = "white";
        dist[i] = 0;
        par[i] = INT_MIN;
    }

    int components = 0;
    for (size_t i = 1; i <= n; i++) {
        if (color[i] == "white") {
            BFS(graph, i);
            components++;
        }
    }

    cout << "components: ";
    return components;
}

int main() {
    cout << "# of vertices: ";
    cin >> n;

    cout << "# of edges: ";
    cin >> m;

    cout << "---Create Graph---\n";
    vector<vector<int>> graph(n + 1); // 1-indexed graph
    color.resize(n + 1, "white");
    dist.resize(n + 1, 0);
    par.resize(n + 1, INT_MIN);
    int u, v;

    for (size_t i = 0; i < m; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int comp = BFS_MOD(graph);
    cout << endl;
    cout << comp << endl;

    print_graph(graph);
    print_dist(graph);
    print_par(graph);

    return 0;
}