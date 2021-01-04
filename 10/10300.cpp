#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, f, a, b, sum;

    scanf("%d", &n);

    while (n--) {
        scanf("%d", &f);
        sum = 0;
        for (int i = 0; i < f; i++) {
            scanf("%d %*d %d", &a, &b);
            sum += (a * b);
        }

        printf("%d\n", sum);
    }
    return 0;
}