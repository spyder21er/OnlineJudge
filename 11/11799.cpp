#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, x, casenum = 1;

    cin >> t;
    while(casenum <= t)
    {
        cin >> n;
        int m = 0;
        while(n--)
        {
            cin >> x;
            m = max(m, x);
        }

        cout << "Case " << casenum++ << ": " << m << endl;
    }

    return 0;
}