#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;

int main()
{
    ULL N, res, pow;
    const int rootroot = 3163;
    const int rootmax = rootroot * rootroot;
    bitset<rootmax+5> sieve;
    vector<ULL> prime;

    //sieve
    sieve.set();
    for (int i = 2; i <= rootroot; i++) {
        if (sieve[i]) {
            int squarei = i * i;
            while (squarei <= rootmax) {
                sieve.reset(squarei);
                squarei += i;
            }
        }
    }

    // filter primes
    for (int i = 2; i < sieve.size(); i++) {
        if (sieve[i])
            prime.push_back(i);
    }
    
    while (scanf("%lld", &N) != EOF) {
        if (N < 2) {
            printf("%lld\n", N);
            continue;
        }

        // remove trailing zeroes
        while (!(N & 1)) {
            N >>= 1;
        }

        res = 1;

        // get the powers of prime factorization (find number of odd factors)
        for (int i = 1; i < prime.size() && prime[i] * prime[i] <= N; i++) {
            if (N % prime[i] == 0) {
                pow = 1;
                while (N % prime[i] == 0) {
                    N /= prime[i];
                    pow++;
                }
                res *= pow;
            }
        }

        if (N > 1) 
            res <<= 1;

        printf("%d\n", res);
    }

    return 0;
}