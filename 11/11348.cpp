#include <bits/stdc++.h>
using namespace std;

int main()
{
    int casenum = 0, T, F, M, S;
    set<int> stamp_types;
    map<int, int> stamp_owner;
    int flag[10001];

    scanf("%d", &T);
    while (casenum++ < T)
    {
        stamp_owner.clear();
        stamp_types.clear();
        scanf("%d", &F);
        for (int curr_friend = 0; curr_friend < F; curr_friend++)
        {
            scanf("%d", &M);
            while (M--)
            {
                scanf("%d", &S);
                if ((stamp_types.insert(S)).second)
                {
                    stamp_owner[S] = curr_friend;
                }
                else
                {
                    if (stamp_owner[S] != curr_friend)
                        stamp_owner.erase(S);
                }
            }
        }

        int unique_stamps = stamp_owner.size();

        memset(flag, 0, sizeof(flag));
        if (unique_stamps == 0)
        {
            printf("Case %d:", casenum);
            for (int i = 0; i < F; i++)
                printf(" %.6f%%", 0.0);
        }
        else
        {
            map<int, int>::iterator it = stamp_owner.begin();
            for (; it != stamp_owner.end(); ++it)
            {
                flag[it->second]++;
            }

            printf("Case %d:", casenum);
            for (int i = 0; i < F; i++)
            {
                printf(" %.6f%%", flag[i] * 100.0 / unique_stamps);
            }
        }
        printf("\n");
    }
}