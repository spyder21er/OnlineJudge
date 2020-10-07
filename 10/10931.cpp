#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;

    while (true) {
        scanf("%d", &N);
        if (!N) break;

        bitset<32> num(N);

        string bitstring = num.to_string();
        int firstset = bitstring.find('1');

        printf("The parity of %s is %d (mod 2).\n", bitstring.substr(firstset, bitstring.length()).c_str(), num.count());
    }

    return 0;
}