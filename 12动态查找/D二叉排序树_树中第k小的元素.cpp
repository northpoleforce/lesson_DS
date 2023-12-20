#include<bits/stdc++.h>

using namespace std;

class TreeNode {
public:
	int *val, *size;
	TreeNode *leftSon, *rightSon;
	TreeNode():val(nullptr), leftSon(nullptr), rightSon(nullptr), size(nullptr) {}
	TreeNode(int v):val(new int(v)), leftSon(nullptr), rightSon(nullptr), size(nullptr) {}
	int calSize(TreeNode *root) {
		if (root == nullptr) return 0;
		if (root->val != nullptr && *root->val == -1) root->val = nullptr;
		if (root->val == nullptr) return 0;
		root->size = new int(calSize(root->leftSon)+calSize(root->rightSon)+1);
		return *root->size;
	}
	int kTH(TreeNode *root, int k) {
		int lSize;
		if (root->leftSon == nullptr || root->leftSon->val == nullptr)
			lSize = 0;
		else
			lSize = *root->leftSon->size;
		if (k <= lSize)
			return kTH(root->leftSon, k);
		else if (k == lSize+1)
			return *root->val;
		else
			return kTH(root->rightSon, k-lSize-1);
	}
};

int main() {
	int t, n, a, k; cin >> t;
	while (t--) {
		cin >> n;
		TreeNode *root = new TreeNode(), *top;
		queue <TreeNode*> que;
		que.push(root);
		while (n--) {
			cin >> a;
			while (!que.empty()) {
				top = que.front();
				if (top->val == nullptr) {
					top->val = new int(a);
					break;
				}
				else if (top->leftSon == nullptr) {
					top->leftSon = new TreeNode(a);
					if (a != -1)
						que.push(top->leftSon);
					break;
				}
				else if (top->rightSon == nullptr) {
					top->rightSon = new TreeNode(a);
					if (a != -1)
						que.push(top->rightSon);
					break;
				}
				else
					que.pop();
			}
		}
		root->calSize(root);
		cin >> k;
		cout << root->kTH(root, k) << "\n";
	}

	return 0;
}