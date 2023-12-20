#include <bits/stdc++.h>

using namespace std;

class TreeNode {
public:
	int *val;
	TreeNode *leftSon, *rightSon;

	TreeNode():val(NULL), leftSon(NULL), rightSon(NULL) {}
	void insert(TreeNode *&root, int key) {
		if (root == NULL) {
			root = new TreeNode();
			root->val = new int(key);
			return;
		}
		if (key < *(root->val))
			insert(root->leftSon, key);
		else
			insert(root->rightSon, key);
	}
	void output(TreeNode *root) {
		if (root == NULL) return;
		output(root->leftSon);
		cout << *(root->val) << " ";
		output(root->rightSon);
	}
	int query(TreeNode *root, int key) {
		if (root == NULL)
			return -1;
		if (key == *(root->val)) return 1;
		int res = -1;
		res = query(root->leftSon, key);
		if (res > -1) return res+1;
		res = query(root->rightSon, key);
		if (res > -1) return res+1;
		return res;
	}
	void destroy(TreeNode *root) {
		if (root == NULL) return;
		destroy(root->leftSon);
		destroy(root->rightSon);
		delete val, leftSon, rightSon;
		delete root;
	}
};

int main() {
	int t; cin >> t;
	int n, a, m;
	while (t--) {
		cin >> n;
		TreeNode *root = NULL;
		for (int i = 0; i < n; ++i) {
			cin >> a;
			root->insert(root, a);
		}
		root->output(root);
		cout << "\n";
		cin >> m;
		while (m--) {
			cin >> a;
			cout << root->query(root, a) << "\n";
		}
	}
	return 0;
}