#include <bits/stdc++.h>

using namespace std;

const int maxx = 1e5+5;

int a[105][105];

int main() {
    int n, m; cin >> m >> n;
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> a[i][j];
    int t, x; cin >> t;
    while (t--) {
        cin >> x;
        int row_l = 1, row_r = m+1, mid;
        while (row_l+1 < row_r) {
            mid = (row_l+row_r)>>1;
            if (a[mid][1] <= x)
                row_l = mid;
            else
                row_r = mid;
        }
        int col_l = 1, col_r = n+1;
        while (col_l+1 < col_r) {
            mid = (col_l+col_r)>>1;
            if (a[row_l][mid] <= x)
                col_l = mid;
            else
                col_r = mid;
        }
        if (a[row_l][col_l] == x)
            cout << "true\n";
        else
            cout << "false\n";
    }


    return 0;
}