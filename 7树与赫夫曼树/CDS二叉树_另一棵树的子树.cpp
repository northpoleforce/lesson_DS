#include<iostream>
#include<string>
#include <queue>
using namespace std;

class TreeNode {
public:
    int val, total;
    TreeNode *father, *lson, *rson;
    TreeNode() {
        val = 0;
        father = lson = rson = NULL;
    }
    TreeNode(char c, TreeNode *f, TreeNode *l, TreeNode *r, int t):val(c), father(f), lson(l), rson(r), total(t) {}
};

int dfs1(TreeNode *now) {
    if (now->lson != NULL && now->lson->val != -1)
        now->total += dfs1(now->lson);
    if (now->rson != NULL && now->rson->val != -1)
        now->total += dfs1(now->rson);
    return now->total += 1;
}
bool check(TreeNode *now1, TreeNode *now2) {
    if (now1 == NULL && now2 == NULL) return 1;
    if (now1 == NULL || now2 == NULL) return 0;
    if (now1->val != now2->val) return 0;
    if (now1->lson != NULL)
        if (!check(now1->lson, now2->lson)) return 0;
    if (now1->rson != NULL)
        if (!check(now1->rson, now2->rson)) return 0;
    return 1;
}
bool dfs(TreeNode *now1, TreeNode *now2) {
    if (now1->val == now2->val && now1->total == now2->total) {
        if (check(now1, now2)) return 1;
    }
    if (now1->lson != NULL && now1->lson->val != -1)
        if (dfs(now1->lson, now2)) return 1;
    if (now1->rson != NULL && now1->rson->val != -1)
        if (dfs(now1->rson, now2)) return 1;
    return 0;
}

int st[1000006];
TreeNode *idx[1000006];

TreeNode* input() {
    int len; cin >> len;
    for (int i = 0; i < len; ++i) cin >> st[i];
    queue <TreeNode*> que;
    TreeNode *root = new TreeNode(st[0], NULL, NULL, NULL, 0), *pre = NULL, *now = NULL;
    que.push(root);
    for (int i = 1; i < len; ++i) {
        pre = que.front();
        now = new TreeNode(st[i], pre, NULL, NULL, 0);
        if (pre->lson == NULL)
            pre->lson = now;
        else
            pre->rson = now;
        if (pre->lson != NULL && pre->rson != NULL)
            que.pop();
        if (st[i] != -1)
            que.push(now);
    }
    return root;
}

int main() {
    int t; cin >> t;
    while (t--) {
        TreeNode *root1 = input();
        TreeNode *root2 = input();
        dfs1(root1); dfs1(root2);
        if (dfs(root1, root2))
            printf("true\n");
        else
            printf("false\n");
    }
    return 0;
}