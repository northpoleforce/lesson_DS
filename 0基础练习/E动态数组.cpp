#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>

using namespace std;



int main()
{
	int t; cin >> t;
	while (t--) {
		char type;
		int n;
		cin >> type >> n;
		if (type == 'I') {
			int* p = new int[n];
			int sum = 0;
			for (int i = 0; i < n; ++i) {
				cin >> *(p + i);
				sum += *(p + i);
			}
			cout << sum / n << "\n";
		}
		if (type == 'C') {
			char* p = new char[n];
			char ch;
			for (int i = 0; i < n; ++i) {
				cin >> *(p + i);
				ch = max(ch, *(p + i));
			}
			cout << ch << "\n";
		}
		if (type == 'F') {
			double* p = new double[n];
			double minx;
			for (int i = 0; i < n; ++i) {
				cin >> *(p + i);
				if (i == 0) minx = *p;
				minx = min(minx, *(p + i));
			}
			cout << minx << "\n";
		}
	}

	return 0;
}