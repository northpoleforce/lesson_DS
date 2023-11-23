#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n, len;
        cin >> n >> len;
        bool **graph = new bool*[n];
        for (int i = 0; i < n; ++i) graph[i] = new bool[n];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) graph[i][j] = false;
        int a, b;
        while (len--) {
            cin >> a >> b;
            graph[a][b] = true;
        }
        int k; cin >> k;
        int **ans = new int*[k+1];
        for (int i = 0; i < k+1; ++i) ans[i] = new int[n];
        for (int i = 0; i < k+1; ++i)
            for (int j = 0; j < n; ++j) ans[i][j] = 0;
        ans[0][0] = 1;
        for (int x = 1; x <= k; ++x) {
            for (int u = 0; u < n; ++u)
                for (int v = 0; v < n; ++v)
                    if (graph[u][v]) {
                        ans[x][v] += ans[x-1][u];
                    }
        }
        cout << ans[k][n-1] << "\n";
        delete[] graph, ans;
    }

    return 0;
}