#include <bits/stdc++.h>
using namespace std;

int main() {
    int T, N, casenum = 0, p_total, q_total, gas;
    int p[100005];
    int q[100005];

    scanf("%d", &T);
    while (casenum++ < T) {
        scanf("%d", &N);
        p_total = 0;
        q_total = 0;
        gas = 0;
        memset(p, 0, sizeof(p));
        memset(q, 0, sizeof(q));
        for (int i = 0; i < N; i++) {
            scanf("%d", p+i);
            p_total += p[i];
        }
        for (int i = 0; i < N; i++) {
            scanf("%d", q + i);
            q_total += q[i];
        }

        // impossible if we require more than what is available
        if (q_total > p_total) {
            printf("Case %d: Not possible\n", casenum);
        } else {
            bool found_station = false, loop_completed = false;
            int station;
            int i = 0;
            while (!found_station || !loop_completed) {
                gas += p[i % N] - q[i % N];
                if (gas >= 0) {
                    if (!found_station) {
                        station = i % N;
                        found_station = true;
                    }
                } else {
                    found_station = false;
                    gas = 0;
                }
                if (found_station && i > N) loop_completed = true;
                i++;
            }
            printf("Case %d: Possible from station %d\n", casenum, station+1);
        }
    }
    return 0;
}