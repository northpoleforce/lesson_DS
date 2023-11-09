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

struct res_info {
    char val;
    int depth;
};
char ans1, ans2;
int max_dis;

res_info dfs1(TreeNode *now, int dep) {
    if (now->lson != NULL && now->rson != NULL 
        && now->lson->val == '#' && now->rson->val == '#' && now->father != NULL) {
        res_info now_info;
        now_info.depth = dep;
        now_info.val = now->val;
        return now_info;
    }
    
    res_info l_res, r_res;
    l_res.val = r_res.val = '\0';
    l_res.depth = r_res.depth = 0;
    if (now->lson != NULL)
        l_res = dfs1(now->lson, dep+1);
    if (now->rson != NULL)
        r_res = dfs1(now->rson, dep+1);

    char lc, rc;
    int dis;
    if (now->lson != NULL) {
        lc = now->val; rc = l_res.val;
        if (lc > rc) swap(lc, rc);
        dis = l_res.depth-dep;
        if (dis > max_dis) {
            max_dis = dis;
            ans1 = lc;
            ans2 = rc;
        } else if (dis == max_dis &&
        (lc < ans1 || (lc == ans1 && rc < ans2))) {
            ans1 = lc;
            ans2 = rc;
        }
    }
    if (now->rson != NULL) {
        lc = now->val; rc = r_res.val;
        if (lc > rc) swap(lc, rc);
        dis = r_res.depth-dep;
        if (dis > max_dis) {
            max_dis = dis;
            ans1 = lc;
            ans2 = rc;
        } else if (dis == max_dis &&
        (lc < ans1 || (lc == ans1 && rc < ans2))) {
            ans1 = lc;
            ans2 = rc;
        }
    }
    if (now->lson != NULL && now->rson != NULL) {
        dis = l_res.depth+r_res.depth-dep*2;
        lc = l_res.val, rc = r_res.val;
        if (lc > rc) swap(lc, rc);
        if (dis > max_dis) {
            max_dis = dis;
            ans1 = lc;
            ans2 = rc;
        }
        else if (dis == max_dis &&
        (lc < ans1 || (lc == ans1 && rc < ans2))) {
            ans1 = lc;
            ans2 = rc;
        }
    }

    res_info now_info;
    if (l_res.depth > r_res.depth) {
        now_info = l_res;
    }
    else if (l_res.depth < r_res.depth) {
        now_info = r_res;
    }
    else {
        if (l_res.val < r_res.val)
            now_info = l_res;
        else
            now_info = r_res;
    }
    return now_info;
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
        max_dis = 0;
        ans1 = ans2 = '\0';
        dfs1(root, 1);
        if (max_dis == 0) {
            cout << "0:\n";
        } else {
            cout << max_dis << ":";
            cout << ans1 << " " << ans2 << "\n";
        }
    }
    return 0;
}