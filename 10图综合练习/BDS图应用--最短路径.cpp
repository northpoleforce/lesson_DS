#include <bits/stdc++.h>

using namespace std;

int n;
int **graph;
int *ans, *pre;

void dfs(int now) {
    for (int v = 0; v < n; ++v)
        if (graph[now][v] > 0 && ans[now]+graph[now][v] < ans[v]) {
            ans[v] = ans[now]+graph[now][v];
            pre[v] = now;
            dfs(v);
        }
}

void dfsOutput(int now, int st) {
    if (now == st) {
        cout << now << " ";
        return;
    }
    dfsOutput(pre[now], st);
    cout << now << " ";
}

int main() {
    int t; cin >> t;
    while (t--) {
        cin >> n;
        graph = new int*[n];
        for (int i = 0; i < n; ++i) graph[i] = new int[n];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) 
                cin >> graph[i][j];
        ans = new int[n];
        pre = new int[n];
        int v0; cin >> v0;
        for (int i = 0; i < n; ++i)
            if (i != v0) {
                for (int i = 0; i < n; ++i) ans[i] = 0x3f3f3f3f;
                ans[v0] = 0;
                cout << v0 << "-" << i << "-";
                dfs(v0);
                cout << ans[i] << "----[";
                dfsOutput(i, v0);
                cout << "]\n";
            }
        delete[] ans, pre;
    }

    return 0;
}