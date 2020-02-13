#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, curr, next, diff, i, sum;
    bool jolly;
    bitset<3005> f;

    while (scanf("%d", &N) != EOF) {
        f.set();
        jolly = true;
        scanf("%d", &curr);
        for (int i = 1; i < N; i++) {
            scanf("%d", &next);
            diff = abs(next - curr);
            if (diff == 0 || diff >= 3000) {
                jolly = false;
            }
            if (jolly) {
                f.flip(diff);
            }
            curr = next;
        }

        if (jolly) {
            for (int i = 1; i < N; i++) {
                if (f.test(i)) {
                    jolly = false;
                    break;
                }
            }
        }

        printf("%s\n", jolly ? "Jolly" : "Not jolly");
    }

    return 0;
}