#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, a, m, x, level, pos;

    while (scanf("%d", &N) != EOF) {
        level = (int) ceil(((sqrt(8.0 * N + 1)) - 1) / 2.0);

        pos = N - (level * (level - 1) / 2);

        a = (level & 1) ? level+1-pos : pos;
        printf("TERM %d IS %d/%d\n", N, a, level+1-a);
    }

    return 0;
}