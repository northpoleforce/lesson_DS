#include <iostream>

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
    in_degree = new int[n];
    out_degree = new int[n];
    for (int i = 0; i < n; ++i) in_degree[i] = out_degree[i] = 0;
    graph = new int*[n];
    for (int i = 0; i < n; ++i) graph[i] = new int[n];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) graph[i][j] = 0;
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
void destroy() {
    delete[] in_degree, out_degree;
    delete[] graph;
}

int main() {
    int t; cin >> t;
    while (t--) {
        char type; cin >> type;
        int n, k; cin >> n;
        string *a = new string[n];
        for (int i = 0; i < n; ++i) cin >> a[i];
        cin >> k;
        string u, v;
        init_edge(n);
        while (k--) {
            cin >> u >> v;
            if (type == 'D')
                add_edge(u, v, a, n);
            else {
                add_edge(u, v, a, n);
                add_edge(v, u, a, n);
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) cout << graph[i][j] << " ";
            cout << "\n";
        }
        for (int i = 0; i < n; ++i) {
            cout << a[i] << "";
            if (type == 'D') {
                if (out_degree[i]+in_degree[i] > 0)
                    cout << ": " << out_degree[i] << " " << in_degree[i] << " " << out_degree[i]+in_degree[i];
            }
            else {
                if (in_degree[i] > 0)
                    cout << ": " << in_degree[i];
            }
            cout << "\n";
        }
        delete[] a;
        destroy();
    }

    return 0;
}