#include <bits/stdc++.h>
using namespace std;

int main() {
    bitset <105> row;
    bitset <105> col;

    int N, b;

    while (true) {
        scanf("%d", &N);
        if (!N) break;
        row.reset();
        col.reset();

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                scanf("%d", &b);
                if (b) {
                    row.flip(i);
                    col.flip(j);
                }
            }
        }

        // if both bitset is zero, we have parity property
        if (row.count() == 0 and col.count() == 0) {
            printf("OK\n");
        } else if (row.count() == 1 and col.count() == 1) {
            // check if we have one on each (row and col) then we can flip that
            // we will find the location of that and store to r, c
            int r = -1, c = -1;
            for (int i = 0; i < row.size(); i++) {
                // this is the row
                if (row.test(i)) r = i;
                // this is the col
                if (col.test(i)) c = i;
                // we end the loop if both are found
                if (r != -1 && c != -1) break;
            }
            printf("Change bit (%d,%d)\n", r+1, c+1);
        } else {
            // we can't do anything here
            printf("Corrupt\n");
        }
    }

    return 0;
}