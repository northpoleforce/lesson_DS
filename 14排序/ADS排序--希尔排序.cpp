#include <bits/stdc++.h>

using namespace std;

int n, a[1000006];

int main() {
	int t; cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; ++i) cin >> a[i];
		for (int gap = n/2; gap >= 1; gap /= 2) {
			for (int i = gap+1; i <= n; ++i)
				for (int j = i; j >= gap+1 && a[j] > a[j-gap]; j -= gap) {
					swap(a[j], a[j-gap]);
				}
			for (int i = 1; i <= n; ++i) cout << a[i] << " ";
			cout << "\n";
		}
		cout << "\n";
	}

	return 0;
}