#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, b, h, w, p, a, e;

    while(cin >> n)
    {
        e = 2e9;
        cin >> b >> h >> w;
        while(h--)
        {
            cin >> p;
            int ai = 0;
            while(ai < w)
            {
                cin >> a;
                if (a >= n && e > p * n)
                        e = p * n;
                ai++;
            }
        }
        if (e < 2e9 && e < b)
            cout << e << endl;
        else
            cout << "stay home" << endl;
    }

    return 0;
}