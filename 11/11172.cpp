#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T, a, b;
    scanf ("%d", &T);
    while (T--)
    {
        scanf ("%d %d", &a, &b);
        if (a == b) 
            cout << "=" << endl;
        else if (a < b)
            cout << "<" << endl;
        else
            cout << ">" << endl;
    }

    return 0;
}