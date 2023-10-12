#include <iostream>

using namespace std;

int main()
{
	int t;
	cin >> t;
	int n, q;
	while (t--) {
		cin >> n;
		int* a = new int[n];
		for (int i = 0; i < n; ++i) cin >> a[i];
		cin >> q;
		int* p = a + n/2;
		cout << *(p - 1) << " " << *(p + 1) << "\n";
		cout << *(p + q-1 - n / 2) << "\n";
		delete[] a;
	}
	return 0;
}