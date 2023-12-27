#include <iostream>

using namespace std;

class HASH {
public:
	int len, C;
	int **ele;
	HASH(int l, int con) {
		len = l;
		C = con;
		ele = new int*[len];
		for (int i = 0; i < len; ++i) ele[i] = nullptr;
	}
	void insert(int num) {
		int idx = num%C;
		if (ele[idx] == nullptr) {
			ele[idx] = new int(num);
			return;
		}
		int t = idx;
		while (1) {
			t = (t+1)%len;
			if (t == idx) return;
			if (ele[t] == nullptr) {
				ele[t] = new int(num);
				return;
			}
		}
	}
	void output() {
		for (int i = 0; i < len; ++i)
			if (ele[i] == nullptr)
				cout << "NULL ";
			else
				cout << *ele[i] << " ";
		cout << "\n";
	}
	void search(int num) {
		int idx = num%C, _idx = idx;
		int cnt = 0;
		while (1) {
			++cnt;
			if (ele[idx] != nullptr && *ele[idx] == num) {
				cout << 1 << " " << cnt << " " << idx+1 << "\n";
				return;
			}
			if (ele[idx] == nullptr) {
				cout << 0 << " " << cnt << " " << "\n";
				return;
			}
			idx = (idx+1)%len;
			if (idx == _idx) {
				cout << 0 << " " << cnt << " " << "\n";
				return;
			}
		}
	}
};

int main() {
	int t, n, m, a, k; cin >> t;
	while (t--) {
		cin >> m >> n;
		HASH *hash =  new HASH(m, 11);
		for (int i = 0; i < n; ++i) {
			cin >> a;
			hash->insert(a);
		}
		hash->output();
		cin >> k;
		while (k--) {
			cin >> a;
			hash->search(a);
		}
	}

	return 0;
}