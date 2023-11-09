#include <bits/stdc++.h>

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
void init_edge(int n) {
    root = new FirstNode[n];
}

void add_edge(char uu, char vv, char a[], int n) {
    int u, v;
    for (int i = 0; i < n; ++i)
        if (a[i] == uu) {
            u = i; break;
        }
    for (int i = 0; i < n; ++i)
        if (a[i] == vv) {
            v = i; break;
        }
    Node *node = new Node(v, NULL);
    if (root[u].first == NULL) {
        root[u].first = node;
        root[u].last = node;
    } else {    
        root[u].last->next = node;
        root[u].last = node;
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        char *a = new char[n];
        for (int i = 0; i < n; ++i) cin >> a[i];
        char u, v;
        init_edge(n);
        while (k--) {
            cin >> u >> v;
            add_edge(u, v, a, n);
        }
        for (int i = 0; i < n; ++i) {
            cout << i << " " << a[i];
            Node *now = root[i].first;
            while (1) {
                if (now == NULL) {
                    cout << "-^";
                    break;
                }
                else {
                    cout << "-" << now->to;
                    now = now->next;
                }
            }
            cout << "\n";
        }
    }

    return 0;
}