#include <bits/stdc++.h>
using namespace std;

int main() {
    char card_input[3];
    int T, casenum = 0, next_card;

    scanf("%d", &T);
    while (casenum++ < T) {
        next_card = 52;

        while (next_card--) {
            scanf("%s", card_input);
            if (next_card == 19)
                printf("Case %d: %s\n", casenum, card_input);
        }
    }
    return 0;
}