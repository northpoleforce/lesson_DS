#include <bits/stdc++.h>

using namespace std;

int n;
string *coin;
double **graph;

int idx(string st) {
    for (int i = 0; i < n; ++i)
        if (st == coin[i]) return i;
}

bool spfa(int st) {
    double *ans = new double[n];
    for (int i = 0; i < n; ++i) ans[i] = 0;
    ans[st] = 1;
    priority_queue< pair<double, int> > que;
    que.push(make_pair(ans[st], st));
    pair <double, int> top;
    double nowCost;
    int nowNode;
    while (!que.empty()) {
        top = que.top(); que.pop();
        nowCost = top.first;
        nowNode = top.second;
        if (nowCost < ans[nowNode]) continue;
        if (nowNode == st && nowCost > 1) return true;
        for (int v = 0; v < n; ++v)
            if (graph[nowNode][v] > 0 && nowCost*graph[nowNode][v] > ans[v]) {
                ans[v] = nowCost*graph[nowNode][v];
                que.push(make_pair(ans[v], v));
            }
    }
    delete[] ans;
    return false;
}

bool check() {
    for (int i = 0; i < n; ++i) {
        if (spfa(i)) return true;
    }
        
    return false;
}

int main() {
    int t, m; cin >> t;
    string ci, cj;
    double r;
    while (t--) {
        cin >> n >> m;
        coin = new string[n];
        for (int i = 0; i < n; ++i) cin >> coin[i];
        graph = new double*[n];
        for (int i = 0; i < n; ++i) graph[i] = new double[n];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) graph[i][j] = 0;
        while (m--) {
            cin >> ci >> r >> cj;
            int u = idx(ci), v = idx(cj);
            graph[u][v] = r;
        }
        if (check())
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}