#include <bits/stdc++.h>
using namespace std;

int main() {
    int T, N, casenum = 0, K, a, b;
    char c;
    string s;

    scanf("%d", &T);
    while (casenum++ < T) {
        scanf(" %d", &N);
        int mat[N][N];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                scanf(" %c", &c);
                mat[i][j] = (int) (c - '0');
            }
        }

        scanf(" %d", &K);
        while (K--) {
            cin >> s;

            if (s == "row") {
                cin >> a >> b;
                for (int c = 0; c < N; c++) {
                    swap(mat[a-1][c], mat[b-1][c]);
                }
            }
            if (s == "col") {
                cin >> a >> b;
                for (int r = 0; r < N; r++) {
                    swap(mat[r][a-1], mat[r][b-1]);
                }
            }
            if (s == "inc") {
                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < N; j++) {
                        mat[i][j] = (mat[i][j] + 1) % 10;
                    }
                }
            }
            if (s == "dec") {
                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < N; j++) {
                        mat[i][j] = (mat[i][j] + 9) % 10;
                    }
                }
            }
            if (s == "transpose") {
                for (int i = 0; i < N; i++) {
                    for (int j = i+1; j < N; j++) {
                        swap(mat[i][j], mat[j][i]);
                    }
                }
            }
        }

        printf("Case #%d\n", casenum);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                printf("%d", mat[i][j]);
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}