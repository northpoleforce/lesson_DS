#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    char val;
    TreeNode *father, *lson, *rson;
    TreeNode() {
        val = '\0';
        father = lson = rson = NULL;
    }
    TreeNode(char c, TreeNode *f, TreeNode *l, TreeNode *r):val(c), father(f), lson(l), rson(r) {}
};

void bfs(TreeNode* now) {
    queue <TreeNode*> que;
    que.push(now);
    while (!que.empty()) {
        now = que.front(); que.pop();
        cout << now->val;
        if (now->lson != NULL && now->lson->val != '0') que.push(now->lson);
        if (now->rson != NULL && now->rson->val != '0') que.push(now->rson);
    }
}
void stack_search(TreeNode* now) {
    stack <TreeNode*> s1;
    stack <bool> s2;
    if (now == NULL) return;
    do {
        if (now != NULL && now->val != '0') {
            s1.push(now);
            s2.push(0);
            now = now->lson;
            continue;
        }
        if (s1.empty()) {
            break;
        }
        if (now == NULL || now->val == '0') {
            if (s2.top() == 0) {
                s2.pop(); s2.push(1);
                now = s1.top()->rson;
                continue;
            } else {
                now = s1.top(); s1.pop();
                s2.pop();
                cout << now->val;
                now = NULL;
            }
        }
    }while (!s1.empty());
}

int main() {
    int t; cin >> t;
    while (t--) {
        string st; cin >> st;
        int len = st.length();
        TreeNode *ptr = NULL, *root = NULL, *pre = NULL;
        pre = root = new TreeNode(st[0], NULL, NULL, NULL);
        for (int i = 1; i < len; i++) {
            while (pre->lson != NULL && pre->rson != NULL) pre = pre->father;
            ptr = new TreeNode(st[i], pre, NULL, NULL);
            if (st[i] == '0') {
                if (pre->lson == NULL) {
                    pre->lson = ptr;
                }
                else if (pre->rson == NULL) {
                    pre->rson = ptr;
                    pre = pre->father;
                }
            } else {
                if (pre->lson == NULL) {
                    pre->lson = ptr;
                    pre = ptr;
                } else {
                    pre->rson = ptr;
                    pre = ptr;
                }
            }
        }
        stack_search(root); cout << "\n";
    }
    return 0;
}