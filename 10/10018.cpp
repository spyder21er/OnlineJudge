#include <bits/stdc++.h>
using namespace std;

long long flip(long long n) {
    long long res = 0;
    while (n) {
        res *= 10;
        res += (n % 10);
        n /= 10;
    }
    return res;
}

bool is_pal(long long n) {
    return flip(n) == n;
}

int main() {
    int n, iterations;
    long long p;

    scanf("%d", &n);

    while (n--) {
        iterations = 0;
        scanf("%lld", &p);

        do {
            p += flip(p);
            iterations++;
        } while (!is_pal(p));

        printf("%d %lld\n", iterations, p);
    }
    return 0;
}