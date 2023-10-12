#include <stack>
#include <queue>
#include <iostream>

using namespace std;

char int2char(int x) {
    return x > 9 ? (char)(x-10+'A'):(char)(x+'0');
}

int main() {
    int t, k; cin >> t;
    double num;
    while (t--) {
        cin >> num >> k;
        stack <char> s;
        queue <char> q;
        int tmp = (int)num;
        if (tmp == 0)
            s.push('0');
        while (tmp) {
            s.push(int2char(tmp%k));
            tmp /= k;
        }
        double tt = num-(int)num;
        for (int i = 0; i < 3; ++i) {
            q.push(int2char((int)(tt*k)));
            tt *= k;
            tt -= (int)tt;
        }
        while (!s.empty()) {
            cout << s.top();
            s.pop();
        }
        cout << ".";
        while (!q.empty()) {
            cout << q.front();
            q.pop();
        }
        cout << "\n";
    }

    return 0;
}