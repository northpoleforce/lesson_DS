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
            int l = 0, r = n+1, mid;
            while (l+1 < r) {
                mid = (l+r)>>1;
                if (a[mid] <= b)
                    l = mid;
                else
                    r = mid;
            }
            if (a[l] == b)
                cout << l << "\n";
            else
                cout << "error\n";
        } 
    }

    return 0;
}