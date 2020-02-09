#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K, M, cost;
    char c;
    string s;
    unordered_map<char, int> cost_table;
    unsigned long long sum;

    scanf("%d", &N);
    while (N--) {
        cost_table.clear();
        sum = 0;
        scanf("%d ", &K);
        while (K--) {
            scanf("%c", &c);
            scanf(" %d ", &cost);
            cost_table[c] = cost;
        }

        scanf("%d ", &M);
        while (M--) {
            getline(cin, s);
            for (int i = 0; i < s.length(); i++) {
                if (cost_table.find(s[i]) != cost_table.end()) {
                    sum += cost_table[s[i]];
                }
            }
        }

        printf("%lld.%02d$\n", sum / 100, (int) (sum % 100));
    }
    return 0;
}