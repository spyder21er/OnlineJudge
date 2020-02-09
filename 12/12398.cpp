#include <bits/stdc++.h>
using namespace std;



int main()
{
    string moves;
    int casenum = 0;
    int board[3][3];

    while (getline(cin, moves)) {
        memset(board, 0, sizeof(int) * 9);
        for (int i = moves.length() - 1; i >= 0; i--) {
            int index = (int) (moves[i] - 'a');

            // itself
            board[index / 3][index % 3] = (board[index / 3][index % 3] + 1) % 10;
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
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                printf("%d", board[i][j]);
                if (j < 2) printf(" "); else printf("\n");
            }
        }
    }

    return 0;
}