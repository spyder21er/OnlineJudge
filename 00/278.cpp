#include <bits/stdc++.h>
using namespace std;

int main() {
    char c;
    int T, m, n, p;

    scanf("%d", &T);

    while (T--) {
        scanf(" %c", &c);
        scanf("%d %d", &m, &n);

        if (c == 'r' || c == 'Q') {
            printf("%d\n", min(m, n));
        }

        if (c == 'k') {
            printf("%d\n", ((m * n) + 1) / 2);
        }

        if (c == 'K') {
            // both are even
            if (!(m & 1) && !(n & 1))
                p = (m*n) / 4;
            else if (m & 1 && n & 1) { // both are odd
                p = ((m - 1) * (n - 1) / 4) + (n / 2) + (m / 2) + 1;
            } else if (n & 1) { // n is odd
                p = (m * (n - 1) / 4) + (n / 2) + 1;
            } else if (n & 1) { // n is odd
                p = ((m - 1) * n / 4) + (m / 2) + 1;
            }
            printf("%d\n", p);
        }
    }
    return 0;
}
