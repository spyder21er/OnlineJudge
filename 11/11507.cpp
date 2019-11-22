#include <bits/stdc++.h>
using namespace std;

int main()
{
    int l;
    string d;
    string current;

    while (true)
    {
        cin >> l;

        if (!l)
            break;

        current = "+x";

        int i = 1;
        while (i < l)
        {
            i++;
            cin >> d;

            if ((d[1] != current[1] && current[1] != 'x') || (d == "No"))
                continue;

            current[0] = (current[1] == 'x') ? 
                (current[0] == d[0] ? '+' : '-') : 
                (current[0] == d[0] ? '-' : '+');
            current[1] = (d[1] == current[1]) ? 'x' : d[1];
        }
        cout << current << endl;
    }
    return 0;
}