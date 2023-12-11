#include <bits/stdc++.h>

using namespace std;

const int maxx = 1e5+5;


int main() {
    int n, m; cin >> n;
    while (n--) {
        cin >> m;
        double l = 0, r = m+0.1, mid;
        for (int i = 0; i < 200; ++i) {
            mid = (l+r)/2;
            if (mid*mid <= m)
                l = mid;
            else
                r = mid;
        }
        cout<<fixed<<setprecision(3)<<l<<endl;
    }

    return 0;
}