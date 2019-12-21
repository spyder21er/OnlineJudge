/**
 * Online Judeg 893 - Y3K Problem
 * Author: leaf.mabz
 * Date: 13122019
 */

#include <bits/stdc++.h>
using namespace std;

bool is_leap(int year)
{
    if (year % 400 == 0) return true;
    if (year % 100 == 0) return false;
    if (year % 4 == 0) return true;
    return false;
}

int main()
{
    int days, dd, mm, yy, nm;
    int month_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    while (true)
    {
        scanf("%d %d %d %d", &days, &dd, &mm, &yy);
        if (!(days + dd + mm + yy)) break;

        if (days == 0) {
            printf("%d %d %d\n", dd, mm, yy);
            continue;
        }

        nm = mm - 1;
        int butal = 0;
        int i = 0;

        while (i < nm) {
            butal += month_days[i];
            i++;
        }

        if (mm > 2 && is_leap(yy)) butal++;

        butal += dd;
        days += butal;
        days--;
        dd = 1; mm = 1;
        
        while (days >= 365242500) { // while we can add 1000 milleniums
            days -= 365242500;
            yy += 1000000;
        }
        
        while (days >= 36524250) { // while we can add 100 milleniums
            days -= 36524250;
            yy += 100000;
        }
        
        while (days >= 3652425) { // while we can add 10 milleniums
            days -= 3652425;
            yy += 10000;
        }

        while (days >= (is_leap(yy) ? 366 : 365)) { // while we can still add year
            days -= (is_leap(yy) ? 366 : 365);
            yy++;
        }

        // printf("%d %d %d %d\n", days, dd, mm, yy);

        while (days >= month_days[mm - 1]) { // while we can still add month
            if (days == 28 && mm == 2 && is_leap(yy)) break;
            days -= month_days[mm - 1];
            if (mm == 2 && is_leap(yy)) days--;
            mm++;
            if (mm == 13) {
                yy++;
                mm = 1;
            }
        }

        dd += days;

        printf("%d %d %d\n", dd, mm, yy);
    }
    return 0;
}
