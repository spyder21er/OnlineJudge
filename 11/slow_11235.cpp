#include <bits/stdc++.h>
using namespace std;

map<int, pair<int, int> > st;
map<int, pair<int, int> > mxs;

int solve(int x, int y)
{
    // case 1: x and y are equal
    if (x==y) return 1;

    // case 2: A_x and A_y has same value
    if (st[x].second == st[y].second)
        return y - x + 1;
    
    // case 3: A_x and A_y split
    int xends = st[x].second;

    return max(solve(x, xends), solve(xends+1, y));
}

int main()
{
    int n, q, x, a, b, curr, start, end, counter;

    while(true)
    {
        st.clear();
        mxs.clear();
        cin >> n;
        if (!n)
            break;
        cin >> q;

        int i = 1;

        cin >> x;
        curr = x;
        counter = 1;
        start = 1;
        i++;
        while(i <= n)
        {
            cin >> x;
            if (x != curr)
            {
                end = i-1;
                for (int j = start; j <= end; j++)
                    st[j] = make_pair(start, end);
                
                start = i;
                mxs[end] = make_pair(counter, curr);

                counter = 1;
                curr = x;
            }
            else
            {
                counter++;
            }
            if (i == n)
            {
                end = n;
                for (int j = start; j <= end; j++)
                    st[j] = make_pair(start, end);

                mxs[end] = make_pair(counter, x);
                break;
            }
            i++;
        }

        while (q--)
        {
            cin >> a >> b;
            cout << solve(a, b) << endl;
        }

    }

    return 0;
}