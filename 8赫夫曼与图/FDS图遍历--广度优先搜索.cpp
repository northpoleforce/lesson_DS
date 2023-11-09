#include <iostream>
#include <queue>

using namespace std;

class Node {
public:
    int to;
    Node* next;
    Node ();
    Node (int t, Node* n):to(t), next(n) {}
};
class FirstNode {
public:
    Node *first, *last;
    FirstNode(): first(NULL), last(NULL) {}
};

FirstNode* root;
int *in_degree, *out_degree, **graph;
void init_edge(int n) {
    graph = new int*[n];
    for (int i = 0; i < n; ++i) graph[i] = new int[n];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) 
            cin >> graph[i][j];
}

void add_edge(string uu, string vv, string a[], int n) {
    int u, v;
    for (int i = 0; i < n; ++i)
        if (a[i] == uu) {
            u = i; break;
        }
    for (int i = 0; i < n; ++i)
        if (a[i] == vv) {
            v = i; break;
        }
    out_degree[u]++;
    in_degree[v]++;
    graph[u][v]=1;
}
void bfs(int now, int n, bool vis[]) {
    vis[now] = true;
    queue <int> q;
    q.push(now);
    while (!q.empty()) {
        now = q.front(); q.pop();
        cout << now << " ";
        for (int v = 0; v < n; ++v)
            if (graph[now][v] == 1 && !vis[v]) {
                vis[v] = true;
                q.push(v);
            }
    }
}
void destroy() {
    delete[] graph;
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n;
        init_edge(n);
        bool *vis = new bool[n];
        for (int i = 0; i < n; ++i) vis[i] = false;
        for (int i = 0; i < n; ++i)
            if (!vis[i]) bfs(i, n, vis);
        cout << "\n";
        delete[] vis;
        destroy();
    }

    return 0;
}