#include<iostream>
#include<string>
#include <queue>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *father, *lson, *rson;
    TreeNode() {
        val = 0;
        father = lson = rson = NULL;
    }
    TreeNode(char c, TreeNode *f, TreeNode *l, TreeNode *r):val(c), father(f), lson(l), rson(r) {}
};

void dfs1(TreeNode *now) {
    if (now->val != -1) cout << now->val << " ";
    if (now->lson != NULL && now->lson->val != -1)
        dfs1(now->lson);
    if (now->rson != NULL && now->rson->val != -1)
        dfs1(now->rson);
}
void dfs2(TreeNode *now) {
    if (now->lson != NULL && now->lson->val != -1)
        dfs2(now->lson);
    if (now->val != -1) cout << now->val << " ";
    if (now->rson != NULL && now->rson->val != -1)
        dfs2(now->rson);
}
void dfs3(TreeNode *now) {
    if (now->lson != NULL && now->lson->val != -1)
        dfs3(now->lson);
    if (now->rson != NULL && now->rson->val != -1)
        dfs3(now->rson);
    if (now->val != -1) cout << now->val << " ";
}

int st[1000006];
TreeNode *idx[1000006];

int main() {
    int t; cin >> t;
    while (t--) {
        int len; cin >> len;
        for (int i = 0; i < len; ++i) cin >> st[i];
        queue <TreeNode*> que;
        TreeNode *root = new TreeNode(st[0], NULL, NULL, NULL), *pre = NULL, *now = NULL;
        que.push(root);
        for (int i = 1; i < len; ++i) {
            pre = que.front();
            now = new TreeNode(st[i], pre, NULL, NULL);
            if (pre->lson == NULL)
                pre->lson = now;
            else
                pre->rson = now;
            if (pre->lson != NULL && pre->rson != NULL)
                que.pop();
            if (st[i] != -1)
                que.push(now);
        }
        dfs1(root); cout << "\n";
        dfs2(root); cout << "\n";
        dfs3(root); cout << "\n";
        cout << "\n";
    }
    return 0;
}