#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, F, T;

    scanf("%d ", &T);

    while (T--) {
        scanf("%d\n%d", &A, &F);

        while (F--) {
            for (int i = 1; i <= A; i++) {
                for (int j = 1; j <= i; j++) {
                    printf("%d", i);
                }
                printf("\n");
            }
            for (int i = A-1; i >= 1; i--) {
                for (int j = 1; j <= i; j++) {
                    printf("%d", i);
                }
                printf("\n");
            }
            if (F > 0) printf("\n");
        }
        if (T > 0) printf("\n");
    }
    return 0;
}