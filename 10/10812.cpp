#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, s, d, h;

    scanf("%d", &n);

    while (n--) {
        scanf("%d %d", &s, &d);
        // if d > s or if the diff is odd 
        if (d > s || (s - d) & 1) {
            printf("impossible\n");
        } else {
            h = (s - d) / 2;
            printf("%d %d\n", h + d, h);
        }
    }
    return 0;
}