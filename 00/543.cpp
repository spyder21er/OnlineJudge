#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    int root_m = 1000005;
    bool isprime[root_m];
    vector<int> primes;

    memset(isprime, true, sizeof(isprime));

    //sieve
    for (int i = 2; i * i < root_m; i++) {
        if (isprime[i]) {
            for (int m = 0; i * i + m * i < root_m; m++) {
                isprime[i * i + m * i] = false;
            }
        }
    }

    for (int i = 3; i < root_m; i++) {
        if (isprime[i])
            primes.push_back(i);
    }

    while (true) {
        scanf("%d", &N);
        if (!N) break;

        for (auto x: primes) {
            if (isprime[N - x]) {
                printf("%d = %d + %d\n", N, x, N-x);
                break;
            }
        }
    }

    return 0;
}