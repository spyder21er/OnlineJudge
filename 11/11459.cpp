#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> p;
    map<int, int> snadder;
    int T, a, b, c, d, from, to;

    scanf("%d", &T);

    while (T--) {
        snadder.clear();
        p.clear();
        scanf("%d %d %d", &a, &b, &c);
        p.resize(a);
        fill(p.begin(), p.end(), 1);

        while (--b >= 0) {
            scanf("%d %d", &from, &to);
            snadder[from] = to;
        }

        bool not_over = true;
        for (int roll = 0; roll < c; roll++) {
            scanf("%d", &d);
            if (not_over) {
                int player_num = roll % a;
                int new_square = p[player_num] + d;
                new_square = snadder.count(new_square) ? snadder[new_square] : new_square;
                if (new_square >= 100) {
                    p[player_num] = 100;
                    not_over = false;
                } else {
                    p[player_num] = new_square;
                }
            }
        }

        for (int p_num = 0; p_num < p.size(); p_num++) {
            printf("Position of player %d is %d.\n", p_num+1, p[p_num]);
        }
    }
    

    return 0;
}