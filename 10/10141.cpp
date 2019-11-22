#include <bits/stdc++.h>
using namespace std;

int main()
{
    int casenum = 1, n, p, r, mxr;
    double d, mnd;
    string s, proposal, chosen;

    while(true)
    {
        mxr = 0;
        mnd = 1e31;
        cin >> n >> p;
        cin.clear();
        cin.ignore();
        
        if ((n + p) == 0)
            break;
        

        if (casenum > 1)
            cout << endl;

        while(n--)
        {
            getline(cin, s);
        }

        while(p--)
        {
            getline(cin, proposal);

            cin >> d >> r;
            cin.clear();
            cin.ignore();

            if (r > mxr)
            {
                mxr = r;
                mnd = d;
                chosen = proposal;
            }
            if (r == mxr)
            {
                if (d < mnd)
                {
                    mnd = d;
                    chosen = proposal;
                }
            }

            while(r--)
            {
                getline(cin, s);
            }
        }

        cout << "RFP #" << casenum++ << endl << chosen << endl;
    }
    return 0;
}