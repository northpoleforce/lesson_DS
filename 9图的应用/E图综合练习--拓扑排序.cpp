#include <iostream>

using namespace std;

int n; 
int **graph;

void topologicalSorting() {
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
                cout << i << " ";
                for (int j = 0; j < n; ++j)
                    graph[i][j] = 0;
                vis[i] = true;
                break;
            }
        }
    }
    cout << "\n";
    delete[] vis;
}

int main() {
    int t; cin >> t;
    while (t--) {
        cin >> n;
        graph = new int*[n];
        for (int i = 0; i < n; ++i) graph[i] = new int[n];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) cin >> graph[i][j];
        topologicalSorting();
        delete[] graph;
    }

    return 0;
}