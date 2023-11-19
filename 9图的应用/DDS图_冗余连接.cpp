#include <bits/stdc++.h>

using namespace std;

struct Edge{
    int u, v;
};

Edge *edges;
int n;
bool *vis;

void dfs(int now, int forbid) {
    vis[now] = true;
    for (int i = 0; i < n; ++i)
        if (i != forbid) {
            if (edges[i].u == now && !vis[edges[i].v]) dfs(edges[i].v, forbid);
            if (edges[i].v == now && !vis[edges[i].u]) dfs(edges[i].u, forbid);
        }
}

bool check(int m) {
    vis = new bool[n+1];
    for (int i = 1; i <= n; ++i) vis[i] = false;
    dfs(1, m);
    for (int i = 1; i <= n; ++i)
        if (!vis[i]) return false;
    return true;
}

int main() {
    int t; cin >> t;
    while (t--) {
        cin >> n;
        edges = new Edge[n];
        for (int i = 0; i < n; ++i) cin >> edges[i].u >> edges[i].v;

        for (int i = n-1; i >= 0; --i) {
            if (check(i)) {
                cout << edges[i].u << " " << edges[i].v << "\n";
                break;
            }
        }
        delete[] edges;
    }

    return 0;
}