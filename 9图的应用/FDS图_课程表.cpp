#include <iostream>

using namespace std;

int n; 
int **graph;

bool topologicalSorting() {
    bool *vis = new bool[n];
    for (int i = 0; i < n; ++i) vis[i] = false;
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i)
        if (!vis[i]) {
            int inDegree = 0;
            for (int j = 0; j < n; ++j) {
                inDegree += graph[j][i];
            }
            if (inDegree == 0) {
                for (int j = 0; j < n; ++j)
                    graph[i][j] = 0;
                vis[i] = true;
                break;
            }
        }
    }
    bool ok = true;
    for (int i = 0; i < n; ++i)
        if (!vis[i]) {
            ok = false;
            break;
        }
    delete[] vis;
    return ok;
}

int main() {
    int t; cin >> t;
    while (t--) {
        cin >> n;
        graph = new int*[n];
        for (int i = 0; i < n; ++i) graph[i] = new int[n];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) graph[i][j] = 0;
        int len, u, v; cin >> len;
        while (len--) {
            cin >> v >> u;
            graph[u][v] = 1;
        }
        if (topologicalSorting())
            cout << "true\n";
        else
            cout << "false\n";
        delete[] graph;
    }

    return 0;
}