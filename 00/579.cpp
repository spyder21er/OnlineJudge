#include <bits/stdc++.h>
using namespace std;

int main()
{
    int h, s;
    double d;
    while(true)
    {
        scanf("%d:%d", &h, &s);
        if ((h + s) == 0)
            break;
        
        d = (double) ((((h * 5) - s) + 60) % 60) * 6.0;
        d += (double) s / 2.0;
        if (d > 360.0) d -= 360.0;
        if (d < 180.0)
            printf("%.3f\n", d);
        else if (d == 180.0)
            printf("180.000\n");
        else
            printf("%.3f\n", 360.0 - d);
    }
    return 0;
}