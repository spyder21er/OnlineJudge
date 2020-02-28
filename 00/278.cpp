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
            p= min(m, n);
        }
        if (c == 'k') {
            p = ((m * n) + 1) / 2;
        }
        if (c == 'K') {
            p = ((m + 1) / 2) * ((n + 1) / 2);
        }
        printf("%d\n", p);
    }
    return 0;
}
