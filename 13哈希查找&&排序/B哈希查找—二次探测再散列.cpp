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
		int t;
		for (int i = 0; ; ++i) {
			t = (idx+i*i)%len;
			if (ele[t] == nullptr) {
				ele[t] = new int(num);
				return; 
			}
			t = (idx-(i*i)%len+len)%len;
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
		int idx = num%C, t;
		int cnt = 1;
		if (ele[idx] == nullptr) {
			cout << 0 << " " << cnt << "\n";
			return;
		} else if (*ele[idx] == num) {
			cout << 1 << " " << cnt << " " << idx+1 << "\n";
			return;
		}
		for (int i = 1; ; ++i) {
			++cnt;
			t = (idx+i*i)%len;
			if (ele[t] != nullptr && *ele[t] == num) {
				cout << 1 << " " << cnt << " " << t+1 << "\n";
				return;
			} else if (ele[t] == nullptr || t == idx || cnt == len) {
				cout << 0 << " " << cnt << "\n";
				return;
			}
			t = (idx-(i*i)%len+len)%len;
			++cnt;
			if (ele[t] != nullptr && *ele[t] == num) {
				cout << 1 << " " << cnt << " " << t+1 << "\n";
				return;
			} else if (ele[t] == nullptr || t == idx || cnt == len) {
				cout << 0 << " " << cnt << "\n";
				return;
			}
		}
		cout << 0 << " " << cnt<< "\n";
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