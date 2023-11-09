
#include <iostream>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *father, *lson, *rson;
    TreeNode() {
        val = 0;
        father = lson = rson = NULL;
    }
    TreeNode(int c, TreeNode *f, TreeNode *l, TreeNode *r):val(c), father(f), lson(l), rson(r) {}
};

int a[10004], b[10004];

TreeNode* build_tree(int al, int ar, int bl, int br) {
    if (ar < al) return NULL;
    if (al == ar) {
        TreeNode *now = new TreeNode(a[ar], NULL, NULL, NULL);
        return now;
    }
    int mid = al;
    for (; mid <= ar; ++mid)
        if (a[mid] == b[br]) break;
    int lcnt = mid-al;
    TreeNode *now = new TreeNode(a[mid], NULL, build_tree(al, mid-1, bl, bl+lcnt-1), build_tree(mid+1, ar, bl+lcnt, br-1));
    return now;
}

int dfs(TreeNode *now) {
    if (now->lson == NULL && now->rson == NULL) {
        return now->val;
    }
    int res = 0x7fffffff;
    if (now->lson != NULL)
        res = min(res, dfs(now->lson));
    if (now->rson != NULL)
        res = min(res, dfs(now->rson));
    return res;
}
void dfs_delete(TreeNode *now) {
    if (now->lson != NULL)
        dfs_delete(now->lson);
    if (now->rson != NULL)
        dfs_delete(now->rson);
    delete now;
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        for (int i = 1; i <= n; ++i) cin >> b[i];
        TreeNode *root = build_tree(1, n, 1, n);
        cout << dfs(root) << "\n";
        dfs_delete(root);
    }
    return 0;
}