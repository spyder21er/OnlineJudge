#include<bits/stdc++.h>
using namespace std;

int divisors(int n) {
    if (n == 1) return 1;
    if (n < 4) return 2;
    int f, ncopy = n, total = 1;

    for (int i = 2; i * i <= ncopy; i++) {
        f = 1;
        while (n % i == 0) {
            f++;
            n /= i;
        }
        total *= f;
    }

    if (n != 1) total *= 2;

    return total;
}

int main() {
    int N, L, U, D, H, dcount;

    scanf("%d", &N);

    while (N--) {
        scanf("%d %d", &L, &U);

        H = 0;
        D = 0;
        for (int i = L; i <= U; i++) {
            dcount = divisors(i);
            if (dcount > D) {
                D = dcount;
                H = i;
            }
        }

        printf("Between %d and %d, %d has a maximum of %d divisors.\n", L, U, H, D);
    }
 
    return 0;
}