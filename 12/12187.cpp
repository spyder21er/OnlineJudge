#include <bits/stdc++.h>
using namespace std;

bool defeats(const int a, const int b, const int heirs)
{
    // Determine if a defeats b
    return ((a+1) % heirs) == b;
}

void simulate(vector<vector<int> > &lands, int heirs)
{
    // identify defeated lands
    int defeated_lands[lands.size()][lands[0].size()];
    
    for (int i = 0; i < lands.size(); ++i)
    {
        for (int j = 0; j < lands[i].size(); ++j)
        {
            // top
            if (i > 0)
                if (defeats(lands[i - 1][j], lands[i][j], heirs))
                {
                    defeated_lands[i][j] = 1;
                    continue;
                }
            // bottom
            if (i < lands.size() - 1)
                if (defeats(lands[i + 1][j], lands[i][j], heirs))
                {
                    defeated_lands[i][j] = 1;
                    continue;
                }

            // left
            if (j > 0)
                if (defeats(lands[i][j-1], lands[i][j], heirs))
                {
                    defeated_lands[i][j] = 1;
                    continue;
                }

            // right
            if (j < lands[i].size() - 1)
                if (defeats(lands[i][j+1], lands[i][j], heirs))
                {
                    defeated_lands[i][j] = 1;
                    continue;
                }
            defeated_lands[i][j] = 0;
        }
    }

    for (int i = 0; i < lands.size(); ++i)
    {
        for (int j = 0; j < lands[i].size(); ++j)
        {
            lands[i][j] += (heirs - defeated_lands[i][j]);
            lands[i][j] %= heirs;
        }
    }
}

void print(vector<vector<int> > &lands)
{
    for(int i = 0; i < lands.size(); ++i)
    {
        for(int j = 0; j < lands[i].size(); ++j)
        {
            printf("%d", lands[i][j]);
            if(lands[i].size() > j+1)
                printf(" ");
        }
        printf("\n");
    }
}

int main()
{
    vector<vector<int> > lands;
    vector<int> land;
    int N, R, C, K, L;
    scanf("%d%d%d%d", &N, &R, &C, &K);
    while(N+R+C+K)
    {
        // scan land
        lands.clear();
        for (int i = 0; i < R; ++i)
        {
            land.clear();
            for (int j = 0; j < C; ++j)
            {
                scanf("%d", &L);
                land.push_back(L);
            }
            lands.push_back(land);
        }

        while(K--)
        {
            simulate(lands, N);
        }

        print(lands);
        scanf("%d%d%d%d", &N, &R, &C, &K);
    }
    return 0;
}