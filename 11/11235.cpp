#include <bits/stdc++.h>
using namespace std;

vector< pair<int, pair<int, int> > > st;
vector< pair<int, int> > A;

int query(int a, int b, int i = 1)
{
    // single element max = 1
    if (a == b) return 1;

    // leaf
    if (2 * i >= st.size()) return b - a + 1;

    // also leaf
    if (st[2 * i].first == 0 && st[2 * i + 1].first == 0)
        return b - a + 1;

    // within range
    if (a <= st[i].second.first && b >= st[i].second.second)
        return st[i].first;

    // outside range
    if (a > st[i].second.second || b < st[i].second.first)
        return 0;

    // not in left then look right
    if (a > st[2 * i].second.second)
        return query(a, b, 2 * i + 1);

    // not in right then look left
    if (b < st[2 * i + 1].second.first)
        return query(a, b, 2 * i);

    // overlap
    return max(
        query(a, st[2 * i].second.second, 2 * i), 
        query(st[2 * i + 1].second.first, b, 2 * i + 1)
    );
}

void build(int s, int e, int i = 1)
{
    if (s == e)
    {
        st[i].first = A[s].second - A[s].first + 1;
        st[i].second = A[s];
        return;
    }

    int mid = (s + e) / 2;
    build(s, mid, 2 * i);
    build(mid + 1, e, 2 * i + 1);

    st[i].first = max(st[2*i].first, st[2*i+1].first);
    st[i].second = make_pair(st[2 * i].second.first, st[2 * i + 1].second.second);

    return;
}

int main()
{
    int n, q, x, a, b, i, curr, start, end;

    while(true)
    {
        st.clear();
        A.clear();
        A.push_back(make_pair(0, 0)); // padding for convenience

        cin >> n;
        if (!n)
            break;
        cin >> q;

        i = 1;
        while(i <= n)
        {
            cin >> x;
            if (i == 1)
            {
                curr = x;
                start = i;
            }
            if (x != curr)
            {
                end = i-1;
                A.push_back(make_pair(start, end));
                start = i;
                curr = x;
            }
            if (i == n)
            {
                A.push_back(make_pair(start, n));
            }
            i++;
        }

        int sz = A.size() - 1;
        st.resize(pow(2, ceil(log2(sz)) + 1));
        build(1, sz);
  
        while (q--)
        {
            cin >> a >> b;
            cout << query(a, b) << endl;
        }
    }

    return 0;
}