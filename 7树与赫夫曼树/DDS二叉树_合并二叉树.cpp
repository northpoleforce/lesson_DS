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
TreeNode* dfs(TreeNode *now1, TreeNode *now2, TreeNode *now) {
    if (now1 != NULL && now1->val != -1) now->val += now1->val;
    if (now2 != NULL && now2->val != -1) now->val += now2->val;

    if (now1 != NULL && now1->lson != NULL && now1->lson->val != -1)
        if (now2 == NULL || now2->lson == NULL || now2->lson->val == -1)
            now->lson = dfs(now1->lson, NULL, new TreeNode(0, now, NULL, NULL, 0));
        else
            now->lson = dfs(now1->lson, now2->lson, new TreeNode(0, now, NULL, NULL, 0));
    else 
    if (now2 != NULL && now2->lson != NULL && now2->lson->val != -1)
        if (now1 == NULL || now1->lson == NULL || now1->lson->val == -1)
            now->lson = dfs(NULL, now2->lson, new TreeNode(0, now, NULL, NULL, 0));
        else
            now->lson = dfs(now1->lson, now2->lson, new TreeNode(0, now, NULL, NULL, 0));
    if (now1 != NULL && now1->rson != NULL && now1->rson->val != -1)
        if (now2 == NULL || now2->rson == NULL || now2->rson->val == -1)
            now->rson = dfs(now1->rson, NULL, new TreeNode(0, now, NULL, NULL, 0));
        else
            now->rson = dfs(now1->rson, now2->rson, new TreeNode(0, now, NULL, NULL, 0));
    else
    if (now2 != NULL && now2->rson != NULL && now2->rson->val != -1)
        if (now1 == NULL || now1->rson == NULL || now1->rson->val == -1)
            now->rson = dfs(NULL, now2->rson, new TreeNode(0, now, NULL, NULL, 0));
        else
            now->rson = dfs(now1->rson, now2->rson, new TreeNode(0, now, NULL, NULL, 0));
    return now;
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
        TreeNode *root = new TreeNode(0, NULL, NULL, NULL, 0);
        root = dfs(root1, root2, root);
        dfs1(root); cout << "\n";
        dfs2(root); cout << "\n";
        dfs3(root); cout << "\n";
        cout << "\n";
    }
    return 0;
}