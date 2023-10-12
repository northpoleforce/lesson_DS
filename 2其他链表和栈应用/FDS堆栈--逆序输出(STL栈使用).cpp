#include<iostream>
#include<string>
#include<stack>
using namespace std;

stack <char> s;

int main() {
    string str;
    int t; cin >> t;
    while (t--) {
        cin >> str;
        int len = str.length();
        for (int i = 0; i < len; ++i) {
            if (str[i] == '#' && !s.empty())
                s.pop();
            else if (str[i] != '#') s.push(str[i]);
        }
        string ans = "";
        while (!s.empty()) {
            ans = s.top()+ans;
            s.pop();
        }
        if (ans == "")
            cout << "NULL\n";
        else
            cout << ans << "\n";
    }
    return 0;
}