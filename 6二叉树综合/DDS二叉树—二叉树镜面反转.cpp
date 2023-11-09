
#include <iostream>
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

void dfs_transform(TreeNode *now) {
    if (now->lson != NULL && now->rson != NULL 
        && now->lson->val == '#' && now->rson->val == '#') {
        return;
    }
    
    TreeNode *tmp = now->lson;
    now->lson = now->rson;
    now->rson = tmp;
    int res = 0;
    if (now->lson != NULL)
        dfs_transform(now->lson);
    if (now->rson != NULL)
        dfs_transform(now->rson);
    return;
}
void dfs1(TreeNode *now) {
    if (now->val != '#') cout << now->val << " ";
    if (now->lson != NULL)
        dfs1(now->lson);
    if (now->rson != NULL)
        dfs1(now->rson);
}
void dfs2(TreeNode *now) {
    if (now->lson != NULL)
        dfs2(now->lson);
    if (now->val != '#') cout << now->val << " ";
    if (now->rson != NULL)
        dfs2(now->rson);
}
void dfs3(TreeNode *now) {
    if (now->lson != NULL)
        dfs3(now->lson);
    if (now->rson != NULL)
        dfs3(now->rson);
    if (now->val != '#') cout << now->val << " ";
}
TreeNode* list[1000006];
void bfs(TreeNode* now) {
    int tot = 1, st = 1;
    list[tot] = now;
    while (st <= tot) {
        now = list[st++];
        cout << now->val << " ";
        if (now->lson != NULL && now->lson->val != '#') {
            list[++tot] = now->lson;
        }
        if (now->rson != NULL && now->rson->val != '#') {
            list[++tot] = now->rson;
        }
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
            if (st[i] == '#') {
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
        if (root == NULL || root->val == '#') {
            cout << "NULL\n" << "NULL\n" << "NULL\n" << "NULL\n";
        } else {
            dfs_transform(root);
            dfs1(root); cout << "\n";
            dfs2(root); cout << "\n";
            dfs3(root); cout << "\n";
            bfs(root); cout << "\n";
        }
    }
    return 0;
}