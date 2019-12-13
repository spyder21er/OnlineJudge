/**
 * Online Judge 1261 - String Popping
 * Author: leaf.mabz
 */

#include <bits/stdc++.h>
using namespace std;


typedef map<size_t, bool> mib;
typedef mib::iterator mibIter;

mib poptable;
vector<mib> DP(26, poptable);

/**
 * This function converts a string of 'a' and 'b' into a
 * binary representation. For example "babbbaaabb" has 5 
 * groups: b, a, bbb, aaa, bb so it is converted into 5 
 * bits => 00111 where ones represent groups that can be
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

    // has one group and not poppable
    if (size == 1 && str == 0) return false;

    bitset<25> bs (str);

    // has only one poppable at the edge
    if ((int) bs.count() == 1 && (str == 1 || str == (1 << (size - 1)))) return false;

    // odd number of groups and bit at the very middle is set
    if ((size & 1) && (bs.test(size >> 1))) return true;

    // all groups are poppable
    if ((int) bs.count() == size) return true;

    // let's check if it is already solved and return the solution
    hash< bitset<25> > hasher;
    size_t key = hasher(bs); // we will use hash of the bitset as key
    if (DP[size].find(key) != DP[size].end()) return DP[size][key];

    // let's also check the reverse
    bitset<25> bscopy = bs;
    for (int i = 0; i < (size >> 1); i++)
    {
        bool temp = bscopy[i];
        bscopy[i] = bscopy[size - i - 1];
        bscopy[size - i - 1] = temp;
    }
    key = hasher(bscopy);
    if (DP[size].find(key) != DP[size].end()) return DP[size][key];

    // else we will solve it manually
    bool result = false;
    for (int i = 0; i < size; i++)
    {
        if (bs.test(i))
        {
            int new_str = str;

            // if it is at the edge
            if (i == 0 || i == (size - 1)) {
                // pop that edge and solve
                if (i == 0)
                    new_str >>= 1;
                else
                    new_str -= (1 << (size-1));

                if (pop(new_str, size - 1)) 
                {
                    result = true;
                    break;
                }
            } else { // at the middle
                // we remove the bits left and right of i
                new_str = (str >> (i + 2));
                new_str <<= 1;
                new_str += 1;
                new_str <<= (i-1);
                int right_part = 0;
                for (int j = 0; j < (i-1); j++)
                {
                    right_part <<= 1;
                    right_part += 1;
                }
                new_str += (right_part & str);

                // since we remove left and right bits, our size is now size - 2
                if (pop(new_str, size - 2)) 
                {
                    result = true;
                    break;
                }
            }
        }
    }

    DP[size][key] = result;
    return result;
}

int main()
{
    string s;
    pair<int, int> parsed;
    int t;

    scanf("%d", &t);
    while (t--)
    {
        cin >> s;
        parsed = parse(s);
        int size = parsed.second, str = parsed.first;
        cout << (pop(str, size) ? 1 : 0) << endl;
    }
    return 0;
}
