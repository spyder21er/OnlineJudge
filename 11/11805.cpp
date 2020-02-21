#include <bits/stdc++.h>
using namespace std;

int main() {
    int T, N, K, P, nn, casenum = 0;

    scanf("%d", &T);
    while (casenum < T) {
        scanf("%d %d %d", &N, &K, &P);
        nn = (K + P) % N;
        printf("Case %d: %d\n", ++casenum, (nn) ? nn : N);
    }
    return 0;
}