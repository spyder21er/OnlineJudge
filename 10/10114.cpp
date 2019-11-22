#include <bits/stdc++.h>
using namespace std;

int main() {
    int dur, dpc, m, prev_m, month;
    double dwp, amt, p, prev_p, loan, mP;
    double dpr[105];
    while (true)
    {
        scanf("%d %lf %lf %d", &dur, &dwp, &amt, &dpc);
        if(dur <= 0) break;
        loan = amt;
        mP = loan / dur;
        amt += dwp;
        prev_m = -1;
        while(dpc--) {
            scanf("%d %lf", &m, &p);
            p = 1.0 - p;
            if (m > prev_m + 1)
                fill(dpr+(prev_m+1),dpr+m,prev_p);
            dpr[m] = p;
            prev_m = m; prev_p = p;
        }
        fill(dpr + (m+1), dpr + 102, p);

        month = 0;
        amt *= dpr[month];
        while (true)
        {
            if (loan < amt) break;
            loan -= mP;
            month++;
            amt *= dpr[month];
        }
        printf("%d month", month);
        (month == 1) ? printf("\n") : printf("s\n");
    }
    return 0;
}