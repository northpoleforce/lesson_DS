#include <bits/stdc++.h>

using namespace std;

int n;
int graph[105][105];
bool to[105][105], chosen[105][105], vis[105];

bool dfs(int now, int st, int ed) {
    if (now == ed) return false;
    if (vis[st] && now == st) return false;
    vis[now] = true;
    for (int v = 0; v < n; ++v)
        if (!vis[v] && to[now][v] && ((now != st && v != ed) || (now != ed && v != st)))
            if(!dfs(v, st, ed)) return false;
    return true;
}

bool check(int a, int b, int u, int v) {
    memset(vis, 0, sizeof(vis));
    if (!dfs(a, a, b)) return false;
    if (u == -1 && v == -1) return true;
    if (graph[a][b] >= graph[u][v]) return false;
    return true;
}

int main() {
    while (cin >> n) {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) cin >> graph[i][j];
        int q, a, b;
        cin >> q;
        memset(to, 0, sizeof(to));
        for (int i = 0; i < q; ++i) {
            cin >> a >> b;
            a--; b--;
            to[a][b] = to[b][a] = true;
        }
        int ans = 0;
        for (int k = 0; k < n-1; ++k) {
            int u = -1, v = -1;
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    if (i != j && !to[i][j] && check(i, j, u, v)) {
                        u = i; v = j;
                    }
            if (u != -1 && v != -1) {
                to[u][v] = to[v][u] = true;
                ans += graph[u][v];
            }
        }
        cout << ans << "\n";
    }

    return 0;
}