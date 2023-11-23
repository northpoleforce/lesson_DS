#include <bits/stdc++.h>

using namespace std;

priority_queue < pair<int, int> > que;

int main() {
    int n;
    cin >> n;
    int **graph = new int*[n];
    for (int i = 0; i < n; ++i) graph[i] = new int[n];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) cin >> graph[i][j];
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                graph[i][j] |= graph[i][k]&graph[k][j];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) cout << graph[i][j] << " ";
        cout << "\n";
    }

    return 0;
}