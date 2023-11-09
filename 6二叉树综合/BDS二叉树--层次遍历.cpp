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
        bfs(root); cout << "\n";
    }
    return 0;
}