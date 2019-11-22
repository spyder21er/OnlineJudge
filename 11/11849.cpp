#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, M, input, count;
    set<int> jack;
    while (true)
    {
        jack.clear();
        count = 0;
        scanf ("%d %d", &N, &M);
        if (N+M == 0) break;
        while (N--) {
            scanf ("%d", &input);
            jack.insert(input);
        }

        while (M--)
        {
            scanf("%d", &input);
            if (!(jack.insert(input)).second)
            {
                count++;
            }
        }

        cout << count << endl;
    }
    return 0;
}