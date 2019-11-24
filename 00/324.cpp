#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;

struct bigint
{
    vector<ULL> n;
    const static ULL BASE = 1e12;
    const static int BASE_DEG = 12;

    bigint(){}

    bigint(ULL _n)
    {
        n.push_back(_n);
        carry();
    }

    void carry()
    {
        for (int i = 0; i < n.size(); i++)
        {
            if (n[i] >= BASE)
            {
                if (n.size() <= i + 1) n.push_back(0);

                n[i+1] += n[i] / BASE;
                n[i] = n[i] % BASE;
            }
        }
    }

    bigint operator * (int _n)
    {
        bigint res;
        res.n.resize(n.size());
        copy(n.begin(), n.end(), res.n.begin());
        for (int i = 0; i < res.n.size(); i++)
        {
            res.n[i] *= _n;
        }
        res.carry();

        return res;
    }

    void operator= (const bigint a)
    {
        n.resize(a.n.size());
        copy(a.n.begin(), a.n.end(), n.begin());
    }
};

ostream &operator<<(ostream &out, bigint a)
{
    for (int i = a.n.size() - 1; i >= 0; i--)
    {
        if (i < a.n.size() - 1)
            out << setfill('0') << setw(a.BASE_DEG) << a.n[i];
        else
            out << a.n[i];
    }
    return out;
}

int main()
{
    int n;
    vector<bigint> fact;
    vector<int> freq;
    fact.push_back(bigint(1));
    fact.push_back(bigint(1));
    for (int i = 2; i <= 366; i++)
    {
        fact.push_back(fact[i-1] * i);
    }

    while (true)
    {
        freq.clear();
        freq.resize(10);
        cin >> n;
        if (!n) break;

        int digit_count = fact[n].n.size();

        for (int i = 0; i < digit_count; i++)
        {
            ULL chunk = fact[n].n[i];
            int counter = fact[n].BASE_DEG;
            while (chunk)
            {
                freq[chunk % 10]++;
                chunk /= 10;
                counter--;
            }
            if (i < digit_count-1) freq[0] += counter;
        }

        cout << n << "! --" << endl;
        for (int i = 0; i < 10; i++)
        {
            if (i != 0 && i != 5) cout << " ";
            cout << "   (" << i << ")" << setw(5) << freq[i];
            if (i == 4 || i == 9) cout << endl;
        }
    }

    return 0;
}