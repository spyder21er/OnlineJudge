#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c, d, res;
    const int k = 3 * 360;

    while (scanf("%d %d %d %d", &a, &b, &c, &d), a || b || c || d) {
        res = k;

        res += (((a + 40) - b) % 40) * 9;
        res += (((c + 40) - b) % 40) * 9;
        res += (((c + 40) - d) % 40) * 9;

        printf("%d\n", res);
    }

    return 0;
}