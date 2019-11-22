#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    int ss[3];
    scanf("%d", &t);
    for(int tNum = 1; tNum <= t; tNum++) {
        printf("Case %d: ", tNum);
        scanf("%d %d %d", ss, ss+1, ss+2);
        sort(ss, ss+3);
        printf("%d\n", ss[1]);
    }
    return 0;
}