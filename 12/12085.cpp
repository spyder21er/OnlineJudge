#include <bits/stdc++.h>
using namespace std;

void printSuffix(int curr, int prev) {
    if (curr != prev)
    {
        printf("-");
        if (prev == 2000000000) {
            printf("%d", prev);
        } else {
            int pow10 = 10;
            while ((curr / pow10) != (prev / pow10)) {
                pow10 *= 10;
            }
            printf("%d", (prev % pow10));
        }
    }
}

int main()
{
    unsigned int N, cp, prev, curr, casenum = 0;
    bool start;

    while (true) {
        scanf("%d", &N);
        if (!N) break;
        printf("Case %d:\n", ++casenum);
        scanf("%d", &cp);
        N--; prev = cp; curr = cp;
        printf("0%d", cp);
        if (!N) printf("\n");
        while (N--) {
            scanf("%d", &cp);
            if (cp != prev + 1) { // new start
                printSuffix(curr, prev);
                printf("\n");
                printf("0%d", cp);
                curr = cp;
            }
            prev = cp;
            if (!N) {
                printSuffix(curr, prev);
                printf("\n");
            }
        }
        printf("\n");
    }

    return 0;
}