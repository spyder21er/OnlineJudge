#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T, bits, k;

    scanf("%d", &T);
    while(T--)
    {
        scanf("%d %d", &bits, &k);
        printf("%d\n", k ^ (k >> 1));
    }
    return 0;
}
