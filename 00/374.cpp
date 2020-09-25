#include <bits/stdc++.h>
using namespace std;

int main()
{
    unsigned int  B, P, M, res;

    while(scanf("%d", &B) != EOF) {
        scanf("%d\n%d", &P, &M);

        B = B % M;
        res = 1;

        while (P > 0) {
            if (P & 1) {
                res = (res * B) % M;
            } 
            B = (B * B) % M;
            P = P >> 1;
        }

        printf("%d\n", res);
    }

    return 0;
}