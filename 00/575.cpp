#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    char num[100];

    while (true)
    {
        scanf("%s", num);
        if (num[0] == '0' && num[1] == '\0') break;

        int res = 0;
        for (int i = 0; i < strlen(num); i++) {
            res += ((num[i] - '0') * ((1 << (strlen(num) - i)) - 1));
        }

        printf("%d\n", res);
    }
    

    return 0;
}