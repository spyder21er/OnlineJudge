#include <bits/stdc++.h>
using namespace std;

int main() {
    const int btsz = 105;
    bitset<btsz> coins;
    vector<int> left;
    vector<int> right;
    int M, N, K, P, coin;
    char comp;

    scanf("%d", &M);

    while(M--) {
        coins.set();
        scanf("%d %d", &N, &K);

        while(K--) {
            left.clear();
            right.clear();
            scanf("%d", &P);
            //left
            for (int i = 0; i < P; i++) {
                scanf("%d", &coin);
                left.push_back(coin);
            }
            //right
            for (int i = 0; i < P; i++) {
                scanf("%d", &coin);
                right.push_back(coin);
            }

            scanf(" %c", &comp);
            // printf("case %d->%c\n", M, comp);
            
            if (comp == '=') {
                for (int i = 0; i < left.size(); i++) {
                    coins.reset(left[i]);
                    coins.reset(right[i]);
                }
            }
        }

        if (btsz - coins.count() == N - 1) {
            for (int i = 1; i <= N; i++) {
                if (coins.test(i)) {
                    printf("%d\n", i);
                    break;
                }
            }
        } else {
            printf("0\n");
        }

        if (M > 0) printf("\n");
    }

    return 0;
}