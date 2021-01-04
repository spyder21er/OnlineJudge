#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, l, swapper, res, i, j;
    bool not_sorted;
    int A[55];

    scanf("%d", &n);

    while (n--) {
        res = 0;
        scanf("%d", &l);
        for (i = 0; i < l; i++) {
            scanf("%d", A + i);
        }

        // bubble sort
        do {
            not_sorted = false;
            for (i = 1; i < l; i++) {
                if (A[i-1] > A[i]) {
                    // swap
                    swapper = A[i-1];
                    A[i-1] = A[i];
                    A[i] = swapper;
                    res++;
                    not_sorted = true;
                }
            }
            l--;
        } while (not_sorted);

        printf("Optimal train swapping takes %d swaps.\n", res);
    }

    return 0;
}