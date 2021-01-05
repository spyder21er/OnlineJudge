#include <bits/stdc++.h>
using namespace std;

int main() {
    int row_sum[155], A[155][155];
    int tc, n, all_best, kadane_best_so_far, kadane_curr;

    scanf("%d", &tc);

    while (tc--) {
        scanf("%d", &n);
        all_best = -10000;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &A[i][j]);
                A[i][j + n] = A[i][j];
                A[i + n][j] = A[i][j];
                A[i + n][j + n] = A[i][j];
            }
        }

        for (int l = 0; l < 2 * n; l++) {
            memset(row_sum, 0, sizeof(row_sum));
            for (int r = l; r < 2 * n && r < l + n; r++) {
                kadane_best_so_far = -10000;
                for (int row = 0; row < 2 * n; row++) {
                    row_sum[row] += A[row][r];
                }
                for (int top = 0; top < n; top++) {
                    kadane_curr = 0;
                    for (int bot = top; bot < 2 * n && bot < top + n; bot ++) {
                        kadane_curr = max(-10000, kadane_curr + row_sum[bot]);
                        kadane_best_so_far = max(kadane_best_so_far, kadane_curr);
                    }
                }
                all_best = max(all_best, kadane_best_so_far);
            }
        }

        printf("%d\n", all_best);
    }

    return 0;
}
