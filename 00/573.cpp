#include <bits/stdc++.h>
using namespace std;

int main()
{
    int H, D, U, F;
    while (true)
    {
        scanf ("%d %d %d %d", &H, &U, &D, &F);
        if (!H) break;
        int day = 0;
        double snail = 0.0, speed = (double) U;
        double fatigue = F * U / 100.0;
        bool fail = false;
        while (true)
        {
            day++;
            snail += speed;
            if (snail > H) break;
            snail -= D;
            if (snail < 0)
            {
                fail = true;
                break;
            }
            if (speed > 0.0)
            {
                speed = max((speed - fatigue), 0.0);
            }
        }
        if (fail)
            cout << "failure on day " << day << endl;
        else
            cout << "success on day " << day << endl;
    }
    return 0;
}