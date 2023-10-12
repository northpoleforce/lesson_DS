#include <stack>
#include <queue>
#include <string>
#include <iostream>

using namespace std;

int t, n[100], g[100][10000];

int get_pos(int num) {
    for (int i = 0; i < t; ++i) {
        for (int j = 0; j < n[i]; ++j)
            if (g[i][j] == num) return i;
    }
    return -1;
}

int main() {
    cin >> t;
    queue < queue<int> > q1, q2;
    for (int i = 0; i < t; ++i) {
        cin >> n[i];
        for (int j = 0; j < n[i]; ++j) cin >> g[i][j];
    }
    string cmd;
    int num;
    bool first = true;
    while (1) {
        cin >> cmd;
        if (cmd == "STOP") break;
        if (cmd == "ENQUEUE") {
            cin >> num;
            int pos = get_pos(num), pos1;
            bool ok = false;
            while (!q1.empty()) {
                pos1 = get_pos(q1.front().front());
                if (pos == pos1 && !ok) {
                    q1.front().push(num);
                    ok = true;
                }
                q2.push(q1.front());
                q1.pop();
            }
            if (!ok) {
                queue <int> q;
                q.push(num);
                q2.push(q);
            }
            while (!q2.empty()) {
                q1.push(q2.front());
                q2.pop();
            }
        }
        if (cmd == "DEQUEUE") {
            if (first) {
                cout << q1.front().front();
                first = false;
            } else
                cout << " " << q1.front().front();
                
            q1.front().pop();
            if (q1.front().empty()) q1.pop();
        }
    }

    return 0;
}