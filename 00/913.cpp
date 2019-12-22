#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;

int main()
{
    ULL N;
    while (scanf("%lld", &N) != EOF) {
        printf("%lld\n", 3 * ((N * N + 2 * N - 5) / 2));
    }
    return 0;
}