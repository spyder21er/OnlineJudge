#include <bits/stdc++.h>
using namespace std;

int fast_mod_pow(int n, int p, int m) {
    int res = 1;

    n = n % m;

    if (p == 0) return (1 % m);
    if (n == 0) return 0;

    while (p > 0) {
        if (p & 1) 
            res = (res * n) % m;
        
        p >>= 1;
        n = (n * n) % m;
    }

    return res;
}

int main()
{
    int T, n, k, d, m, res, Ai, casenum = 0;

    scanf("%d", &T);

    while (T--) {
        res = 0;
        
        scanf("%d %d %d", &n, &k, &d);

        for (int i = 0; i < n; i++) {
            scanf("%d", &Ai);

            res = (res + (Ai % d)) % d;
        }

        m = fast_mod_pow(n, k - 1, d);
        m = (m * (k % d)) % d;
        res = (res * m) % d;

        printf("Case %d: %d\n", ++casenum, res);
    }

    return 0;
}