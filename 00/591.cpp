#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, st, sum, ave, casenum = 0;
    int stacks[55];

    while (true) {
        scanf("%d", &n);
        if (!n) break;

        sum = 0;
        ave = 0;

        for (int i = 0; i < n; i++) {
            scanf("%d", stacks + i);
            sum += stacks[i];
        }

        ave = sum / n;
        sum = 0;
        
        for (int i = 0; i < n; i++) {
            if (stacks[i] > ave) {
                sum += stacks[i] - ave;
            }
        }

        printf("Set #%d\nThe minimum number of moves is %d.\n\n", ++casenum, sum);
    }
    return 0;
}