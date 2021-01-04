#include <bits/stdc++.h>
using namespace std;

int g(int n) {
    int sum;
    while (n >= 10) {
        sum = 0;
        while (n) {
            sum += (n % 10);
            n /= 10;
        }
        n = sum;
    }
    return n;
}

int main() {
    int n;

    scanf("%d", &n);

    while (n) {
        printf("%d\n", g(n));

        scanf("%d", &n);
    }
    return 0;
}