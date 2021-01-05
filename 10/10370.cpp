#include <bits/stdc++.h>
using namespace std;

int main() {
    int grades[1005];
    int t, n, above;
    double ave, sum;

    scanf("%d", &t);

    while (t--) {
        sum = 0;
        above = 0;
        scanf("%d", &n);

        for (int i = 0; i < n; i++) {
            scanf("%d", grades + i);
            sum += (double) grades[i];
        }

        ave = sum / (double) n;

        for (int i = 0; i < n; i++) {
            if ( (double) grades[i] > ave) {
                above++;
            }
        }

        printf("%.3lf%%\n", 100.0 * (double) above / (double) n);

    }

    return 0;
}