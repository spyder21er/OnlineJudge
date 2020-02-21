#include <bits/stdc++.h>
using namespace std;

int find_max(bitset<55> d, int m) {
    for (int i = m; i < 55; i++) {
        if (!(d.test(i))) {
            return (i > 52) ? -1 : i;
        }
    }
}

int main() {
    int A, B, C, X, Y, sh, sm, sl, bh, bl;
    bitset<55> deck;

    while (true) {
        deck.reset();
        scanf("%d%d%d%d%d", &A, &B, &C, &X, &Y);
        if (!(A+B+C+X+Y)) break;
        deck.set(A);
        deck.set(B);
        deck.set(C);
        deck.set(X);
        deck.set(Y);
        sh = max(max(A, B), C);
        sl = min(min(A, B), C);
        sm = (A + B + C) - sh - sl;
        bh = max(X, Y);
        bl = (X+Y) - bh;

        if ((sm > bh) || (sm > bl && sh > bh)) {
            printf("%d\n", -1);
        } else if (bl > sh) {
            printf("%d\n", find_max(deck, 1));
        } else if (bh > sh && sm > bl) {
            printf("%d\n", find_max(deck, sh));
        } else {
            printf("%d\n", find_max(deck, sm));
        }
    }
    return 0;
}