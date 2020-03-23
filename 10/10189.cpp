#include <bits/stdc++.h>
using namespace std;

int main() {
    int mine_field[105][105], m, n, casenum = 0;
    char c;
    vector< pair< int, int > > mines;

    while (true) {
        mines.clear();
        scanf("%d %d", &m, &n);
        if (!(m+n)) break;
        if (casenum) printf("\n");
        printf("Field #%d:\n", ++casenum);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                scanf(" %c", &c);
                if (c == '*') {
                    mine_field[i][j] = -1;
                    mines.push_back(make_pair(i, j));
                } else {
                    mine_field[i][j] = 0;
                }
            }
        }

        int neighbors_x[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
        int neighbors_y[8] = {-1, -1, -1, 0, 1, 1, 1, 0};

        for (auto mine : mines) {
            for (int i = 0; i < 8; i++) {
                int row = mine.first + neighbors_y[i];
                int col = mine.second + neighbors_x[i];
                if (row >= 0 && row < m && col >= 0 && col < n && mine_field[row][col] != -1) {
                    mine_field[row][col]++;
                }
            }
        }

        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mine_field[i][j] == -1) 
                    printf("*");
                else
                    printf("%d", mine_field[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}