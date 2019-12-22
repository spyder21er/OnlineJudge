#include <bits/stdc++.h>
using namespace std;

bool is_leap(int year)
{
    if (year % 400 == 0)
        return true;
    if (year % 100 == 0)
        return false;
    if (year % 4 == 0)
        return true;
    return false;
}

int main()
{
    int sign_beg[12] = {21, 20, 21, 21, 22, 22, 23, 22, 24, 24, 23, 23};
    int month_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string sign[12] = { "aquarius",
                        "pisces",
                        "aries",
                        "taurus",
                        "gemini",
                        "cancer",
                        "leo",
                        "virgo",
                        "libra",
                        "scorpio",
                        "sagittarius",
                        "capricorn"};

    int T, casenum = 0, d, m, y, i, date, nm, butal, days;

    scanf("%d", &T);

    while (casenum < T) {
        casenum++;
        days = 280;
        butal = 0;
        scanf("%d", &date);

        m = date / 1000000;
        d = (date / 10000) % 100;
        y = date % 10000;

        nm = m - 1;
        i = 0;

        while (i < nm)
        {
            butal += month_days[i];
            i++;
        }

        if (m > 2 && is_leap(y))
            butal++;

        butal += d;
        days += butal;
        days--;
        d = 1;
        m = 1;

        while (days >= (is_leap(y) ? 366 : 365)) { // while we can still add year
            days -= (is_leap(y) ? 366 : 365);
            y++;
        }

        // printf("%d %d %d %d\n", days, dd, m, y);

        while (days >= month_days[m - 1]) { // while we can still add month
            if (days == 28 && m == 2 && is_leap(y)) break;
            days -= month_days[m - 1];
            if (m == 2 && is_leap(y)) days--;
            m++;
            if (m == 13) {
                y++;
                m = 1;
            }
        }

        d += days;

        i = m - 1;
        if (d < sign_beg[i]) i = ((i+11) % 12);

        printf("%d %02d/%02d/%d %s\n", casenum, m, d, y, sign[i].c_str());
    }

    return 0;
}