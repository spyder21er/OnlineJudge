#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, r, n, st, median, mid, ans;
    vector<int> sts;

    scanf("%d", &t);

    while (t--) {
        ans = 0;
        sts.clear();
        scanf("%d", &r);
        n = r;

        while (r--) {
            scanf("%d", &st);
            sts.push_back(st);
        }

        sort(sts.begin(), sts.end());
        mid = n / 2;
        median = (n & 1) ? sts[mid] : (sts[mid] + sts[mid - 1]) / 2;
        for (auto st : sts) {
            ans += abs(st - median);
        }

        printf("%d\n", ans);
    }
    
    return 0;
}