#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, sum, rem;

    // while (scanf("%d", &n) != EOF) {
    //     scanf("%d", &k);
    //     sum = n;
    //     while (n / k) {
    //         sum += (n / k);
    //         rem = n % k;
    //         n = (n / k) + rem;
    //     }
    //     printf("%d\n", sum);
    // }

    while (scanf("%d", &n) != EOF) {
        scanf("%d", &k);
        printf("%d\n", n + (n-1)/(k-1));
    }

    return 0;
}