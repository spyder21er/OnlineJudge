#include <bits/stdc++.h>
using namespace std;

int main() {
    int S, B, l, r, mn, mx, left_bro, right_bro;
    unordered_map<int, int> l_map;
    unordered_map<int, int> r_map;
    
    while (true) {
        l_map.clear();
        r_map.clear();
        scanf("%d %d", &S, &B);
        if (!(S+B)) break;

        while(B--) {
            scanf("%d %d", &l, &r);

            // left side
            if (l_map.find(l) != l_map.end()) {
                left_bro = l_map[l];
            } else {
                left_bro = l - 1;
            }

            // right side
            if (r_map.find(r) != r_map.end()) {
                right_bro = r_map[r];
            } else {
                right_bro = r + 1;
            }

            if (left_bro > 0) {
                l_map[right_bro] = left_bro;
                printf("%d ", left_bro);
            } else {
                l_map[right_bro] = 0;
                printf("* ");
            }

            if (right_bro <= S) {
                r_map[left_bro] = right_bro;
                printf("%d\n", right_bro);
            } else {
                r_map[left_bro] = S + 1;
                printf("*\n");
            }
        }

        printf("-\n");
    }
    return 0;
}