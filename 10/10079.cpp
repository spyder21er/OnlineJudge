#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, ans;

    while(scanf("%lld", &n), n >= 0) {
        ans = (n & 1) ? ((n + 1) / 2) * n + 1 : (n / 2) * (n + 1) + 1;
        printf("%lld\n", ans);
    }

    return 0;
}