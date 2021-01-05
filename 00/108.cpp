#include <bits/stdc++.h>
using namespace std;

int main() {
    int row_sum[105], A[105][105];
    int n, all_best = 0, kadane_best_so_far, kadane_curr;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    for (int l = 0; l < n; l++) {
        memset(row_sum, 0, sizeof (row_sum));
        for (int r = l; r < n; r++) {
            kadane_best_so_far = 0;
            kadane_curr = 0;
            for (int row = 0; row < n; row++) {
                row_sum[row] += A[row][r];
                kadane_curr = max(0, kadane_curr + row_sum[row]);
                kadane_best_so_far = max(kadane_best_so_far, kadane_curr);
            }
            all_best = max(all_best, kadane_best_so_far);
        }
    }

    printf("%d\n", all_best);

    return 0;
}
