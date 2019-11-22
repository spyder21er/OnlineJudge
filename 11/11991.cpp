#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, x, k, v;
    map<int, vector<int> > res;

    while(cin >> n)
    {
        res.clear();
        cin >> m;

        int i = 1;

        while(i <= n)
        {
            cin >> x;
            res[x].push_back(i);
            i++;
        }

        while(m--)
        {
            cin >> k >> v;
            if (res[v].size() >= k)
                cout << res[v][k-1] << endl;
            else
                cout << 0 << endl;
        }
    }

    return 0;
}