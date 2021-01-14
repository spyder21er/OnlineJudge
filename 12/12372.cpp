#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, cn = 0, l, w, h;

    scanf("%d", &t);

    while (cn < t) {
        scanf("%d %d %d", &l, &w, &h);
        printf("Case %d: %s", ++cn, ((l <= 20) && (w <= 20) && (h <= 20)) ? "good\n" : "bad\n");
    }
    
    return 0;
}