#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, T, casenum = 0;

    scanf("%d", &T);

    while(casenum < T) {
        printf("Case %d: ", ++casenum);
        scanf("%d\n%d", &a, &b);
        a = a >> 1;
        b = (b + 1) >> 1;
        printf("%d\n", (b*b) - (a*a));
    }

    return 0;
}