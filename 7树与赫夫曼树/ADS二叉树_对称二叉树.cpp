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
bool dfs(TreeNode *now1, TreeNode *now2) {
    if (now1 == NULL && now2 == NULL) return 1;
    if (now1 == NULL || now2 == NULL) return 0;
    if (now1->val != now2->val) return 0;
    bool ok = 1;
    if (now1->lson != NULL && now1->lson->val != -1)
        if (!dfs(now1->lson, now2->rson)) return 0;
    if (now1->rson != NULL && now1->rson->val != -1)
        if (!dfs(now1->rson, now2->lson)) return 0;
    if (now2->lson != NULL && now2->lson->val != -1)
        if (!dfs(now1->rson, now2->lson)) return 0;
    if (now2->rson != NULL && now2->rson->val != -1)
        if (!dfs(now1->lson, now2->rson)) return 0;
    return 1;
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
        if (dfs(root, root))
            printf("true\n");
        else
            printf("false\n");
    }
    return 0;
}