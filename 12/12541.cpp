#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T, m, d, y, bd;
    int lowest = 2000000000;
    int highest = 0;
    string youngest, oldest, name = "test";
    cin >> T;
    while (T--)
    {
        cin >> name >> d >> m >> y;
        bd = y*10000+m*100+d;
        if (bd < lowest)
        {
            oldest = name;
            lowest = bd;
        }
        if (bd > highest)
        {
            youngest = name;
            highest = bd;
        }
    }
    cout << youngest << endl << oldest << endl;
    return 0;
}