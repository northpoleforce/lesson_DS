#include <bits/stdc++.h>

using namespace std;

class TreeNode {
public:
	int *val;
	TreeNode *pre, *leftSon, *rightSon;

	TreeNode():val(NULL), pre(NULL), leftSon(NULL), rightSon(NULL) {}
	void insert(TreeNode *&root, TreeNode *pre, int key) {
		if (root == NULL) {
			root = new TreeNode();
			root->val = new int(key);
			root->pre = pre;
			return;
		}
		if (key < *(root->val))
			insert(root->leftSon, root, key);
		else
			insert(root->rightSon, root, key);
	}
	void _delete(TreeNode *&root, int key) {
		TreeNode *pos = query_ptr(root, key);
		if (pos == NULL) return;

		TreeNode *bigger = findSmallest(pos->rightSon);
		if (bigger == NULL) {
			if (pos->leftSon != NULL) {
				pos->val=pos->leftSon->val;
				pos->rightSon=pos->leftSon->rightSon;
				pos->leftSon=pos->leftSon->leftSon;
			} else
				deleteNode(root, pos);
		}
		else {
			pos->val = bigger->val;
			deleteNode(root, bigger);
		}
	}
	void deleteNode(TreeNode *&root, TreeNode *node) {
		if (node->pre != NULL) {
			if (node->pre->leftSon != NULL && node->pre->leftSon == node) {
				node->pre->leftSon = node->rightSon;
			}
			if (node->pre->rightSon != NULL && node->pre->rightSon == node) {
				node->pre->rightSon  = node->rightSon;
			}
			if (node->rightSon != NULL)
				node->rightSon->pre = node->pre;
		}
		node->val = NULL;
		node->leftSon = node->rightSon = NULL;
		node = NULL;
	}
	TreeNode* findSmallest(TreeNode *root) {
		if (root == NULL) return root;
		if (root->leftSon == NULL) return root;
		return findSmallest(root->leftSon);
	}
	void output(TreeNode *root) {
		if (root == NULL) return;
		if (root == nullptr) return;
		output(root->leftSon);
		if (root->val != NULL)
			cout << *(root->val) << " ";
		output(root->rightSon);
	}
	int query_times(TreeNode *root, int key) {
		if (root == NULL)
			return -1;
		if (key == *(root->val)) return 1;
		int res = -1;
		res = query_times(root->leftSon, key);
		if (res > -1) return res+1;
		res = query_times(root->rightSon, key);
		if (res > -1) return res+1;
		return res;
	}
	TreeNode* query_ptr(TreeNode *root, int key) {
		if (root == NULL || root->val == NULL)
			return NULL;
		if (key == *(root->val)) return root;
		TreeNode *res = NULL;
		res = query_ptr(root->leftSon, key);
		if (res != NULL) return res;
		res = query_ptr(root->rightSon, key);
		if (res != NULL) return res;
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
			root->insert(root, NULL, a);
		}
		root->output(root); cout << "\n";
		cin >> m;
		while (m--) {
			cin >> a;
			root->_delete(root, a);
			root->output(root); cout << "\n";
		}
	}
	return 0;
}