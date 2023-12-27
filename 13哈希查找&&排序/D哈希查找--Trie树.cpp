#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct Node {
	char *ch;
	int tot;
	Node *next[26];
	Node():ch(nullptr),tot(0) {
		for (int i = 0; i < 26; ++i) next[i] = nullptr;
	}
	Node(char c):ch(new char(c)),tot(1) {
		for (int i = 0; i < 26; ++i) next[i] = nullptr;
	}
};
class Trie {
public:
	Node *root;
	Trie():root(new Node()) {}
	void insert(string str) {
		int len = str.length();
		Node *now = root;
		for (int i = 0, key; i < len; ++i) {
			key = str[i]-'a';
			if (now->next[key] == nullptr) {
				now->next[key] = new Node(str[i]);
				now = now->next[key];
			} else {
				now = now->next[key];
				now->tot++;
			}
		}
	}
	void output() {
		queue <Node*> que;
		que.push(root);
		Node *now = nullptr;
		while (!que.empty()) {
			now = que.front(); que.pop();
			if (now == nullptr) continue;
			if (now->ch != nullptr) cout << *now->ch;
			for (int i = 0; i < 26; ++i)
				que.push(now->next[i]);
		}
		cout << "\n";
	}
	void search(string str) {
		int len = str.length();
		Node *now = root;
		for (int i = 0, key; i < len; i++) {
			key = str[i]-'a';
			if (now->next[key] != nullptr)
				now = now->next[key];
			else {
				cout << "0\n";
				return;
			}
		}
		cout << now->tot << "\n";
	}
};

int main() {
	string str;
	while (cin >> str) {
		Trie *trie = new Trie();
		while (str[0] >= 'a' && str[0] <= 'z') {
			trie->insert(str);
			cin >> str;
		}
		trie->output();
		int t = stoi(str);
		while (t--) {
			cin >> str;
			trie->search(str);
		}
	}

	return 0;
}