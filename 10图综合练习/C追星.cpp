#include <bits/stdc++.h>

using namespace std;

priority_queue < pair<int, int> > que;

int n, m;
int **graph;
int *ans;

int main() {
    int u, v, w;
    while (cin >> n >> m) {
        graph = new int*[n+1];
        for (int i = 1; i <= n; ++i) graph[i] = new int[n+1];
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j) graph[i][j] = 0x3f3f3f3f;
        while (m--) {
            cin >> u >> v >> w;
            graph[u][v] = min(graph[u][v], w);
            graph[v][u] = min(graph[v][u], w);
        }
        que.push(make_pair(0, 1));
        pair<int,int> pii;
        int nowCost, nowNode;
        ans = new int[n+1];
        for (int i = 1; i <= n; ++i) ans[i] = 0x3f3f3f3f;
        ans[1] = 0;
        while (!que.empty()) {
            pii = que.top(); que.pop();
            nowCost = -pii.first;
            nowNode = pii.second;
            if (nowCost > ans[nowNode]) continue;
            for (int v = 1; v <= n; ++v) {
                if (graph[nowNode][v] != 0x3f3f3f3f && graph[nowNode][v]+nowCost < ans[v]) {
                    ans[v] = graph[nowNode][v]+nowCost;
                    que.push(make_pair(-ans[v], v));
                }
            }
        }
        cout << ans[n] << "\n";
    }

    return 0;
}