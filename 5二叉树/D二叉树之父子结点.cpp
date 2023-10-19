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

void dfs1(TreeNode *now, bool cmd) {
    if (now->lson != NULL && now->rson != NULL 
        && now->lson->val == '0' && now->rson->val == '0' && now->father != NULL) {
        if (cmd)
            cout << now->father->val << " ";
        else
            cout << now->val << " ";
    }
    
    if (now->lson != NULL)
        dfs1(now->lson, cmd);
    if (now->rson != NULL)
        dfs1(now->rson, cmd);
}
void dfs3(TreeNode *now) {
    if (now->lson != NULL)
        dfs3(now->lson);
    if (now->rson != NULL)
        dfs3(now->rson);
    if (now->val != '#') cout << now->val;
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
        if (root->lson->val == '0' && root->rson->val == '0')
            cout << root->val << " \n" << root->val << " \n";
        else {
            dfs1(root, 0); cout << "\n";
            dfs1(root, 1); cout << "\n";
        }
    }
    return 0;
}