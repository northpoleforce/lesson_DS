#include<iostream>
#include<string>
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

int dfs(TreeNode *now, int a[], int d, int &id) {
    int res = 0;
    if (now->val >= 'A' && now->val <= 'Z') res += a[++id]*d;
    if ((now->lson == NULL || now->lson->val == '0')
    && (now->rson == NULL || now->rson->val == '0')) {
        return res;
    }
    if (now->lson != NULL && now->lson->val != '0')
        res += dfs(now->lson, a, d+1, id);
    if (now->rson != NULL && now->rson->val != '0')
        res += dfs(now->rson, a, d+1, id);
    return res;
}

int main() {
    int t; cin >> t;
    while (t--) {
        string st; cin >> st;
        int n; cin >> n;
        int *a = new int[n+1];
        for (int i = 1; i <= n; ++i) cin >> a[i];
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
        int id = 0;
        cout << dfs(root, a, 0, id) << "\n";
    }
    return 0;
}
