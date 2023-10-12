#include <stack>
#include <iostream>

using namespace std;

int main() {
    int t; cin >> t;
    string str;
    while (t--) {
        cin >> str;
        int len = str.size();
        stack <int> s;
        bool ok = true;
        for (int i = 0; i < len; ++i) {
            if (str[i] == '(' || str[i] == '[' || str[i] == '{') s.push(str[i]);
            if (str[i] == ')') {
                if (!s.empty() && s.top() == '(')
                    s.pop();
                else {
                    ok = false;
                    break;
                }
            }
            if (str[i] == ']') {
                if (!s.empty() && s.top() == '[')
                    s.pop();
                else {
                    ok = false;
                    break;
                }
            }
            if (str[i] == '}') {
                if (!s.empty() && s.top() == '{')
                    s.pop();
                else {
                    ok = false;
                    break;
                }
            }
        }
        if (!s.empty()) ok = false;
        if (ok)
            cout << "ok\n";
        else
            cout << "error\n";
    }

    return 0;
}