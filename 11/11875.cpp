#include <bits/stdc++.h>
using namespace std;

int main() {
    int T, N, age, casenum = 0;

    scanf("%d", &T);

    while (casenum < T) {
        scanf("%d", &N);
        int mid = N / 2;
        printf("Case %d: ", ++casenum);
        while (N--) {
            scanf("%d", &age);
            if (N == mid) printf("%d\n", age);
        }
    }
    return 0;
}