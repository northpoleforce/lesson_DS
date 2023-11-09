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
void output(TreeNode *now) {
    if (now->father == NULL) {
        cout << now->val << " ";
        return;
    }
    output(now->father);
    cout << now->val << " ";
}
int targetSum;
bool dfs(TreeNode *now, int sum) {
    if (sum == targetSum &&
        (now->lson == NULL || now->lson->val == -1) && (now->rson == NULL || now->rson->val == -1)) {
        output(now); cout << "\n";
        return 1;
    }
    bool ok = 0;
    if (now->lson != NULL && now->lson->val != -1)
        ok |= dfs(now->lson, sum + now->lson->val);
    if (now->rson != NULL && now->rson->val != -1)
        ok |= dfs(now->rson, sum + now->rson->val);
    return ok;
}

int st[1000006];
TreeNode *idx[1000006];

int main() {
    int t; cin >> t;
    while (t--) {
        cin >> targetSum;
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
        if (! dfs(root, root->val))
            cout << "Path not found\n";
        cout << "\n";
    }
    return 0;
}