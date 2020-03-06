#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M, h, k, sum;
    bool doomed;
    int heads[20005];
    multiset<int> knights;

    while (true) {
        knights.clear();
        doomed = false;
        sum = 0;
        scanf("%d %d", &N, &M);

        if (!(N+M)) break;

        for (int i = 0; i < N; i++) {
            scanf("%d", heads+i);
        }

        while (M--) {
            scanf("%d", &k);
            knights.insert(k);
        }
        
        for (int i = 0; i < N; i++) {
            auto it = knights.lower_bound(heads[i]);
            if (it == knights.end()) {
                doomed = true;
                break;
            }
            sum += (*it);
            knights.erase(it);
        }

        if (doomed)
            printf("Loowater is doomed!\n");
        else
            printf("%d\n", sum);
    }

    return 0;
}