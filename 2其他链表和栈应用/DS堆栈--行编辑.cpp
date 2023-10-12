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
        for (int i = 0; i < len; ++i) s.push(str[i]);
        while (!s.empty()) {
            cout << s.top();
            s.pop();
        }
        cout << "\n";
    }
    return 0;
}