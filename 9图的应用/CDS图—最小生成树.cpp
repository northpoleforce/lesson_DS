#include <bits/stdc++.h>

using namespace std;

int n, m; 
string *vertex;
int **graph;

struct Edge {
    string u, v;
    int val, idx;
    bool seleted;
};
Edge *edge;

int find_idx(string s) {
    for (int i = 0; i < n; ++i)
        if (vertex[i] == s) return i;
}

void addEdge(string uu, string vv, int val) {
    int u = find_idx(uu), v = find_idx(vv);
    graph[u][v] = graph[v][u] = val;
}

bool cmp0(const Edge &a, const Edge &b) {
    return a.val < b.val;
}

bool *vis;

bool checkRound(int now, int pre, int root) {
    if (pre != now && now == root) return true;
    for (int i = 0; i < m; ++i) {
        if (edge[i].seleted) {
            int u = find_idx(edge[i].u);
            int v = find_idx(edge[i].v);
            if (u == now && v != pre)
                if (checkRound(v, now, root)) return true;
            if (v == now && u != pre)
                if (checkRound(u, now, root)) return true;
        }
    }       
    return false;
}

int Kruskal() {
    int res = 0;
    sort(edge, edge+m, cmp0);
    for (int i = 0; i < m; ++i) {
        int u = find_idx(edge[i].u);
        int v = find_idx(edge[i].v);
        edge[i].seleted = true;
        if (checkRound(u, u, u) || checkRound(v, v, v)) {
            edge[i].seleted = false;
            continue;
        }
        edge[i].seleted = true;
        res += edge[i].val;
    }
    return res;
}

bool cmp1(const Edge &a, const Edge &b) {
    return a.idx < b.idx;
}

void KruskalOutput() {
    for (int i = 0; i < m; ++i)
        if (edge[i].seleted) {
            if (find_idx(edge[i].u) < find_idx(edge[i].v))
                cout << edge[i].u << " " << edge[i].v << " " << edge[i].val << "\n";
            else
                cout << edge[i].v << " " << edge[i].u << " " << edge[i].val << "\n";
        }
}

int prim(int st) {
    vis = new bool[n];
    for (int i = 0; i < n; ++i) vis[i] = false;
    int res = 0;
    vis[st] = true;
    for (int k = 1; k < n; ++k) {
        int minEdgeVal = 0x7fffffff, u = -1, v = -1;
        for (int i = 0; i < n; ++i)
            if (vis[i]) {
                for (int j = 0; j < n; ++j)
                    if (!vis[j] && graph[i][j] > 0 && graph[i][j] < minEdgeVal) {
                        minEdgeVal = graph[i][j];
                        u = i; v = j;
                    }
            }
        vis[v] = true;
        cout << vertex[u] << " " << vertex[v] << " " << minEdgeVal << "\n";
        res += minEdgeVal;
    }
    return res;
}

int main() {
    cin >> n;
    vertex = new string[n];
    graph = new int*[n];
    for (int i = 0; i < n; ++i) graph[i] = new int[n];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) graph[i][j] = 0;
    for (int i = 0; i < n; ++i) cin >> vertex[i];
    cin >> m;
    edge = new Edge[m];
    for (int i = 0; i < m; ++i) {
        cin >> edge[i].u >> edge[i].v >> edge[i].val;
        edge[i].seleted = false;
        edge[i].idx = i;
        addEdge(edge[i].u, edge[i].v, edge[i].val);
    }
    string st; cin >> st;
    cout << Kruskal() << "\n";
    cout << "prim:\n";
    prim(find_idx(st));
    cout << "kruskal:\n";
    KruskalOutput();

    return 0;
}