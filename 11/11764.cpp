#include <bits/stdc++.h>
using namespace std;

int main() {
    int T, cn = 0, n, prev, curr, high, low;

    scanf("%d", &T);

    while (cn < T) {
        scanf("%d", &n);
        high = low = prev = 0;

        n--;
        scanf("%d", &prev);

        while (n--) {
            scanf("%d", &curr);
            if (curr > prev) high++;
            if (prev > curr) low++;
            prev = curr;
        }
        printf("Case %d: %d %d\n", ++cn, high, low);
    }

    return 0;
}