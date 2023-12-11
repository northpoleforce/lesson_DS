#include <bits/stdc++.h>

using namespace std;

int a[100005];

int main() {
    int n;
    while (cin >> n) {
        for (int i = 1; i <= n; ++i) cin >> a[i];
        int t, b; cin >> t;
        while (t--) {
            cin >> b;
            a[0] = b;
            int i = n;
            for (; i > 0; --i) {
                if (a[i] == b) break;
            }
            if (i == 0)
                cout << "error\n";
            else
                cout << i << "\n";
        } 
    }

    return 0;
}