#include <bits/stdc++.h>
using namespace std;

int sum_of_factors(int n) {
    if (n == 1) return 0;
    int sum = 1;
    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0) {
            sum += i;
            if (i*i != n)
                sum += n/i;
        }
    }

    return sum;
}

int main()
{
    int N;

    printf("PERFECTION OUTPUT\n");

    while (true) {
        scanf("%d", &N);
        if (!N) break;

        printf("%5d  ", N);
        int sum = sum_of_factors(N);
        if (sum == N) {
            printf("PERFECT\n");
        } else if (sum < N) {
            printf("DEFICIENT\n");
        } else {
            printf("ABUNDANT\n");
        }
    }

    printf("END OF OUTPUT\n");

    return 0;
}