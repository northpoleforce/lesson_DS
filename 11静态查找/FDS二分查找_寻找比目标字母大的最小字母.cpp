#include <bits/stdc++.h>

using namespace std;

const int maxx = 1e5+5;

string str;
char target;

int main() {
    int t; cin >> t;
    while(t--) {
        cin >> str >> target;
        int l = -1, r = str.size(), mid;
        while (l+1 < r) {
            mid = (l+r)>>1;
            if (str[mid] > target)
                r = mid;
            else
                l = mid;
        }
        if (r == str.size())
            cout << str[0] << "\n";
        else
            cout << str[r] << "\n";
    }

    return 0;
}