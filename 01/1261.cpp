/**
 * Online Judge 1261 - String Popping
 * Author: leaf.mabz
 */

#include <bits/stdc++.h>
using namespace std;


typedef map<int, bool>::iterator mipIter;
map<int, bool> poptable;

int can_be_popped(int n)
{
    mipIter it = poptable.find(n);
    if (it == poptable.end()) // not found
        return -1;
    
    return (int) it->second;
}

/**
 * This function converts a string of 'a' and 'b' into a
 * binary representation. For example "babbbaaabb" has 5 
 * groups: b, a, bbb, aaa, bb so it is converted into 5 
 * bits => 00011 where ones represent groups that can be
 * popped and zeroes are groups that cannot be popped.
 * The first of the pair is the binary representation and
 * the second is the size.
 */
pair<int, int> parse(string s)
{
    // We will find and group pairs of characters
    char c = s[0];
    int i = 1, result = 0, size = 0, pair, slen = s.length();

    while (true)
    {
        pair = 0;
        if (i < slen)
        {
            while (c == s[i])
            {
                i++;
                pair++;
                if (i >= slen) break;
            }
        }
        result <<= 1;
        result += (int) (pair != 0);
        size++;
        if (i >= slen) break;
        c = s[i];
        i++;
    }

    return make_pair(result, size);
}

bool pop(int str, int size)
{
    // is empty
    if (size == 0) return true;

    // has one group and poppable
    if (size == 1 && str == 1) return true;

    bitset<size> bs (str);

    // has only one poppable at the edge
    if (bs.count() == 1 && (str == 1 || str == (1 << (size - 1)))) return false;

    // odd number of groups and bit at the very middle is set
    if (bs.test(size >> 1)) return true;

    // all groups are poppable
    if (bs.count() == size) return true;

    for (int i = 0; i < size; i++)
    {
        if (bs.test(i))
        {
            // todo:
            return false;
        }
    }
}

int main()
{
    string s;
    pair<int, int> ret;
    // let's test
    while (true)
    {
        cin >> s;
        if (s == "END") break;
        ret = parse(s);
        int size = ret.second, str = ret.first;
        bitset<16> bs (ret.first);
        cout << bs << "|" << ret.second << endl;
        cout << ((size & 1) && ((1 << (size >> 1)) & str)) << endl;
    }
    return 0;
}