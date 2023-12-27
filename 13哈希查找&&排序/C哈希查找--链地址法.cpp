#include <iostream>

using namespace std;

struct Node {
	int data;
	Node *next;
	Node(int d, Node *n):data(d), next(n) {}
};

class Hash {
public:
	int len;
	Node **ele;
	Hash(int l):len(l) {
		ele = new Node*[len];
		for (int i = 0; i < len; ++i) ele[i] = nullptr;
	}
	void insert(int num) {
		int idx = num%len;
		ele[idx];
		ele[idx] = new Node(num, ele[idx]);
	}
	void search(int num) {
		int idx = num%len, cnt = 0;
		Node *now = ele[idx];
		while (now != nullptr) {
			++cnt;
			if (now->data == num) {
				cout << idx << " " << cnt << "\n";
				return;
			}
			now = now->next;
		}
		ele[idx] = new Node(num, ele[idx]);
		cout << "error\n";
	}
};

int main() {
	int n, a, t;
	while (cin >> n) {
		Hash *hash = new Hash(11);
		while (n--) {
			cin >> a;
			hash->insert(a);
		}
		cin >> t;
		while (t--) {
			cin >> a;
			hash->search(a);
		}
	}

	return 0;
}