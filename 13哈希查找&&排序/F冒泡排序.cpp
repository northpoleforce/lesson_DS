#include <iostream>

using namespace std;

class SortList {
public:
	int len, *ele;
	SortList():len(0), ele(nullptr) {}
	void init(int n) {
		len = n;
		ele = new int[len];
		for (int i = 0; i < len; ++i) cin >> ele[i];
	}
	void sort() {
		int t, ans = 0;
		for (int i = 1; i < len; ++i) {
			for (int j = i-1; j >= 0; --j)
				if (ele[j+1] < ele[j]) {
					t = ele[j];
					ele[j] = ele[j+1];
					ele[j+1] = t;
					ans++;
				}
		}
		cout << ans << "\n";
	}
};

int main() {
	int n;
	while (cin >> n) {
		SortList *sl = new SortList();
		sl->init(n);
		sl->sort();
	}

	return 0;
}