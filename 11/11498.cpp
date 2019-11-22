#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen ("11498.in", "r", stdin);
    int k;
    scanf("%d", &k);
    while(k) {
        int x, y, xx, yy;
        scanf("%d %d", &x, &y);
        while(k--) {
            scanf("%d %d", &xx, &yy);
            if(xx == x || yy == y) {
                printf("divisa\n");
            } else if(xx > x && yy > y) {
                printf("NE\n");
            } else if(xx < x && yy > y) {
                printf("NO\n");
            } else if(xx < x && yy < y) {
                printf("SO\n");
            } else if(xx > x && yy < y) {
                printf("SE\n");
            }
        }
        scanf("%d", &k);
    }   
    return 0;
}