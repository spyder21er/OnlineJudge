#include <bits/stdc++.h>
using namespace std;

vector<int> st;
vector<int> depthphi;
unsigned long long phi[2000001];
const int DP_SIZE = 2000000;

int query(int s, int e, int l = 1, int h = DP_SIZE, int i = 1)
{
    if (s <= l && h <= e)
        return st[i];

    if (e < l || h < s)
        return 0;
    
    int mid = (l + h) / 2;
    return query(s, e, l, mid, 2 * i) +
            query(s, e, mid + 1, h, 2 * i + 1);
}

void build(int l, int h, int i = 1)
{
    if (l == h)
    {
        st[i] = depthphi[l];
        return;
    }

    int mid = (l + h) / 2;
    build (l, mid, 2 * i);
    build (mid + 1, h, 2 * i + 1);

    st[i] = st[2*i] + st[2*i+1];
}

void generatePhi()
{
    phi[1] = 1;
    depthphi.push_back(0);
    depthphi.push_back(0);
    for (int i = 2; i <= DP_SIZE; i++)
    {
        if (!phi[i])
        {
            phi[i] = i - 1;
            for (int j = (i << 1); j <= DP_SIZE; j += i)
            {
                if (!phi[j])
                    phi[j] = j;
                phi[j] = phi[j] * (i - 1) / i;
            }
        }
        depthphi.push_back(1 + depthphi[phi[i]]);
    }
}

int main()
{
    int n, t, a, b;
    generatePhi();

    st.resize(pow(2, ceil(log2(DP_SIZE)) + 1));
    build(1, DP_SIZE);

    cin >> t;
    while (t--)
    {
        cin >> a >> b;
        cout << query(a, b) << endl;
    }

    return 0;
}