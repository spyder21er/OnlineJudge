#include <bits/stdc++.h>
using namespace std;

int total(int * M, string indices) {
    int sum = 0;
    for (auto c : indices) {
        sum += M[(int) (c - '0')];
    }
    return sum % 10;
}

int main()
{
    string moves;
    int casenum = 0, scores[9], a, b, c, d, e, f, g, h, i;

    while (getline(cin, moves)) {
        memset(scores, 0, sizeof(scores));
        
        for (int i = moves.length() - 1; i >= 0; i--) {
            int index = (int) (moves[i] - 'a');
            scores[index]++;
        }

        a = total(scores, "013");
        b = total(scores, "0124");
        c = total(scores, "125");
        d = total(scores, "0346");
        e = total(scores, "13457");
        f = total(scores, "2458");
        g = total(scores, "367");
        h = total(scores, "4678");
        i = total(scores, "578");
        printf("Case #%d:\n", ++casenum);
        printf("%d %d %d\n%d %d %d\n%d %d %d\n", a, b, c, d, e, f, g, h, i);
    }

    return 0;
}