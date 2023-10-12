#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
	int t; cin >> t;
	while (t--) {
		int p[2][3];
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < 3; ++j) cin >> p[i][j];
		}
		int* ptr = *p;
		/*cout << p[0][0] << p[0][1] << p[0][2] << "\n";
		cout << *ptr;
		ptr++; cout << *ptr;
		ptr++; cout << *ptr;*/
		/*cout << *(p) << *(p + 1) << *(p + 2) << "\n";
		cout << **p << "!!!\n";
		cout << **(p + 1) << **(p + 2) << "???\n";
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < 3; ++j) cout << **(p + 3 * i + j) << " ";
		}
		cout << "\n";*/
		for (int i = 1; i <= 3; ++i) {
			for (int j = 1; j <= 2; ++j) {
				int jj = 3 - i;
				int ii = j-1;
				/*cout << ii << ":" << jj << "=";*/
				cout << *(ptr + 3 * ii + jj) << " ";
			}
			cout << "\n";
		}
	}

	return 0;
}