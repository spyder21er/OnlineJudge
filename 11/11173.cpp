#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T, bits, k, result;

    scanf("%d", &T);
    while(T--)
    {
        result = 0;
        scanf("%d %d", &bits, &k);
        while(bits>0)
        {
            result <<= 1;
            if (k >= (1<<(bits-1)))
            {
                result += 1;
                k = (1<<bits) - k - 1;
            }
            bits--;
        }
        printf("%d\n", result);
    }
    return 0;
}