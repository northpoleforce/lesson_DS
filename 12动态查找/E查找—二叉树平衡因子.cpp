#include<bits/stdc++.h>

using namespace std;

class TreeNode {
public:
	char *val;
	int *size, *height;
	TreeNode *leftSon, *rightSon;
	TreeNode():val(nullptr), leftSon(nullptr), rightSon(nullptr), size(nullptr), height(nullptr) {}
	TreeNode(char v):val(new char(v)), leftSon(nullptr), rightSon(nullptr), size(nullptr), height(nullptr) {}
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
	int calHeight(TreeNode *root) {
		if (root == nullptr) return 0;
		if (root->val != nullptr && *root->val == '0') root->val = nullptr;
		if (root->val == nullptr) return 0;
		root->height = new int(max(calHeight(root->leftSon), calHeight(root->rightSon))+1);
		return *root->height;
	}
	void output(TreeNode *root) {
		if (root == nullptr || root->val == nullptr) return;
		output(root->leftSon);
		output(root->rightSon);
		int lHeight = 0, rHeight = 0;
		if (root->leftSon != nullptr && root->leftSon->height != nullptr)
			lHeight = *root->leftSon->height;
		if (root->rightSon != nullptr && root->rightSon->height != nullptr)
			rHeight = *root->rightSon->height;
		cout << *root->val << " " << lHeight-rHeight << "\n";
	}
};

int main() {
	int t, n, a, k; cin >> t;
	char ch;
	while (t--) {
		cin >> n;
		TreeNode *root = new TreeNode(), *top;
		queue <TreeNode*> que;
		que.push(root);
		while (n--) {
			cin >> ch;
			while (!que.empty()) {
				top = que.front();
				if (top->val == nullptr) {
					top->val = new char(ch);
					break;
				}
				else if (top->leftSon == nullptr) {
					top->leftSon = new TreeNode(ch);
						que.push(top->leftSon);
					break;
				}
				else if (top->rightSon == nullptr) {
					top->rightSon = new TreeNode(ch);
						que.push(top->rightSon);
					break;
				}
				else
					que.pop();
			}
		}
		root->calHeight(root);
		root->output(root);
	}

	return 0;
}