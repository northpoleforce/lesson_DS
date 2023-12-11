#include <bits/stdc++.h>

using namespace std;

const int maxx = 1e5+5;

int a[maxx], b[maxx], c[maxx];

int main() {
    int n;
    while (cin >> n) {
        for (int i = 1; i <= n; ++i) cin >> a[i];
        int k; cin >> k;
        b[0] = -0x3f3f3f3f;
        for (int i = 1; i <= k; ++i) cin >> b[i];
        int t, x; cin >> t;
        
        c[1] = 1;
        for (int i = 2, j = 1; i <= k && j <= n; ++i)
            for (; j <= n; ++j)
                if (a[j]>b[i-1]) {
                    c[i] = j;
                    break;
                }
        c[k+1] = n+1;

        while (t--) {
            cin >> x;
            int tot = 1;
            bool ok = false;
            for (int i = 1; i <= k; ++i, ++tot)
                if (b[i-1] <= x && x <= b[i]) {
                    tot++;
                    for (int j = c[i]; j < c[i+1]; ++j, ++tot)
                        if (a[j] == x) {
                            ok = true;
                            cout << j << "-" << tot << "\n";
                            break;
                        }
                    break;
                }
            if (!ok) cout << "error\n";
        }
    }
    
    return 0;
}