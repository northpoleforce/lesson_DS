#include <bits/stdc++.h>

using namespace std;

int t[1003], p[1003];

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> t[i] >> p[i];
    int k; cin >> k;
    double wait_time = 0;
    int wait_time_max = 0, final_done_time = 0;
    // , wait_cnt = 0;
    queue <int> q, tq;
    for (int i = 0; i < n; ++i) {
        if (q.size() < k) {
            q.push(t[i]+p[i]);
            final_done_time = max(final_done_time, t[i]+p[i]);
            continue;
        }
        int done_first_time = 0x7fffffff;
        while (!q.empty()) {
            done_first_time = min(done_first_time, q.front());
            tq.push(q.front());
            q.pop();
        }
        while (!tq.empty() && tq.front() != done_first_time) {
            q.push(tq.front());
            tq.pop();
        }
        tq.pop();
        
        if (done_first_time > t[i]) {
            wait_time += done_first_time-t[i];
            // wait_cnt++;
            wait_time_max = max(wait_time_max, done_first_time-t[i]);
            q.push(done_first_time+p[i]);
            final_done_time = max(final_done_time, done_first_time+p[i]);
        } else {
            q.push(t[i]+p[i]);
            final_done_time = max(final_done_time, t[i]+p[i]);
        }
            
        
        while (!tq.empty()) {
            q.push(tq.front());
            tq.pop();
        }
    }
    // printf("%lf\n", wait_time);
    printf("%.1lf %d %d", wait_time/n, wait_time_max, final_done_time);

    return 0;
}