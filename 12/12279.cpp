#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T, x, res, cn = 0;

    while (scanf("%d", &T), T) {
        res = 0;
        while (T--) {
            scanf("%d", &x);

            if (x)
                res++;
            else
                res--;
        }

        printf("Case %d: %d\n", ++cn, res);
    }

    return 0;
}