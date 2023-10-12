#include <stack>
#include <queue>
#include <iostream>

using namespace std;

char ty[100005];
int ti[100005];

int main() {
    queue<int> myQe;
    queue<int> myQA[3];

    int n; cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> ty[i];
    for (int i = 0; i < n; ++i)
        cin >> ti[i];
    for (int i = 0; i < n; ++i) {
        int pos = ty[i]-'A';
        myQA[pos].push(ti[i]);
    }
    for (int i = 0; i < 3; ++i) {
        double sum = 0;
        int cnt = myQA[i].size();
        while (!myQA[i].empty()) {
            sum += myQA[i].front();
            myQA[i].pop();
        }
        printf("%d\n", (int)(sum/cnt));
    }

    return 0;
}