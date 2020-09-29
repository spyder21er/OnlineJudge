#include <bits/stdc++.h>
using namespace std;

int main()
{
    bool isnegative[100001];
    bool isprime[100001];
    memset(isprime, 1, sizeof(isprime));
    memset(isnegative, 0, sizeof(isnegative));

    int limit = 100000;
    int sroot = sqrt(limit) + 1;

    // sieve
    for (int i = 2; i < sroot; i++) {
        if (isprime[i]) {
            for (int m = 0; i * i + m * i <= limit; m++) {
                isprime[i * i + m * i] = false;
            }
        }
    }

    for (int i = 1; 4 * i + 1 <= limit; i++) {
        int f = 4 * i + 1;
        if (isprime[f]) {
            for (int j = 1; f * j <= limit; j++) {
                isnegative[f*j] = isnegative[f*j] ^ true;
            }
            if (f <= sroot) {
                for (int p = 2; (int) pow(f, p) <= limit; p++) {
                    int powered = (int) pow(f, p);
                    for (int j = 1; powered * j <= limit; j++) {
                        isnegative[powered*j] = isnegative[powered*j] ^ true;
                    }
                }
            }
        }
    }


    int t, n;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);
        printf("%c\n", isnegative[n] ? '-' : '+');
    }

    return 0;
}