#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T, n;

    scanf("%d", &T);

    while(T--) {
        scanf("%d", &n);
        printf("%d\n", (abs(315 * n + 36962) / 10) % 10);
    }

    return 0;
}