#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, n, k, max_mn;

    while (true)     {
        scanf("%d %d", &m, &n);

        if (!(m + n)) break;
 
        max_mn = max(m, n);

        if (!m || !n)
            k = 0;
        else if (m == 1 || n == 1)
            k = max_mn;
        else if (m == 2 || n == 2) {
            k = 4 * (max_mn / 4) +  2 * min((max_mn % 4), 2);
        } else k = ((m * n) + 1) / 2;

        printf("%d knights may be placed on a %d row %d column board.\n", k, m, n);
    }

    return 0;
}