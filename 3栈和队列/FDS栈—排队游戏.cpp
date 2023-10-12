#include <stack>
#include <queue>
#include <string>
#include <iostream>

using namespace std;


int main() {
    string str; cin >> str;
    int len = str.size();
    char l = str[0], r;
    for (int i = 0; i < len; ++i)
        if (str[i] != l)
            r = str[i];
    stack <int> s;
    for (int i = 0; i < len; ++i) {
        if (str[i] == l)
            s.push(i);
        else {
            cout << s.top() << " " << i << "\n";
            s.pop();
        }
    }

    return 0;
}