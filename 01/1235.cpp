#include <bits/stdc++.h>
using namespace std;

// returns number of rolls from key a to b
// a and b are 4 chars length
int dist(char * a, char * b) {
    int sum = 0;

    for (int i = 0; i < 4; i++) {
        int d = abs(a[i] - b[i]);
        sum += min(d, 10 - d);
    }

    return sum;
}

int main() {
    int T, N, n;
    char key[5];
    int adjmat[505][505];
    vector< char* > keys;
    char zero[] = "0000";

    scanf("%d", &T);
    while (T--) {
        memset(adjmat, 0, sizeof(adjmat));
        keys.clear();
        keys.push_back(zero);

        scanf("%d", &N);
        int i = 0;
        while (i++ <= N) {
            scanf("%s", key);
            keys.push_back(key);
            for (int j = 0; j < i; j++) {
                adjmat[i][j] = dist(key, keys[j]);
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                printf("%d ", adjmat[i][j]);
            }
            printf("\n");
        }
    }
    
    return 0;
}