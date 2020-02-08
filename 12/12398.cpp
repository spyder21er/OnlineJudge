#include <bits/stdc++.h>
using namespace std;



int main()
{
    char moves[105];
    int casenum = 0;
    int board[3][3];

    while (scanf("%c"), moves) {
        memset(board, 0, sizeof(int) * 9);
        for (int i = moves.length() - 1; i >= 0; i--) {
            int index = (int) (moves[i] - 'a');

            // up
            if ((index / 3) > 0)
                board[(index / 3) - 1][index % 3] = (board[(index / 3) - 1][index % 3] + 1) % 10;
            // down
            if ((index / 3) < 2)
                board[(index / 3) + 1][index % 3] = (board[(index / 3) + 1][index % 3] + 1) % 10;
            // left
            if ((index % 3) > 0)
                board[(index / 3)][(index % 3) - 1] = (board[(index / 3)][(index % 3) - 1] + 1) % 10;
            // right
            if ((index % 3) < 2)
                board[(index / 3)][(index % 3) + 1] = (board[(index / 3)][(index % 3) + 1] + 1) % 10;
        }

        printf("Case #%d:\n", ++casenum);

    }

    return 0;
}