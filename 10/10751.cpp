#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T, t, n;

    scanf("%d", &T);
    t = T;
    
    while(t) {
        scanf("%d", &n);
        if (T != t--) printf("\n");
        if (n > 2)
            printf("%.3f\n", 4 * n - 4 + ((n-2) * (n-2)) * sqrt(2));
        else {
            printf("%.3f\n", n == 2 ? 4.0 : 0.0);
        }
    }

    return 0;
}