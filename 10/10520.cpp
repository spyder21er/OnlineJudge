#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;

int main() 
{
    int n, an1, i, j, k;
    ULL maxa, maxb, maxc;
    ULL A[21][21];
    
    while(cin >> n)
    {
        cin >> A[n][1];
        
        for (i = n; i > 0; i--)
        {
            for (j = 1; j <= n; j++)
            {
                if (j == 1 && i == n) continue;
                
                if (i >= j)
                {
                    maxa = 0;
                    maxb = 0;
                    if (i < n)
                    {
                        for (k = i + 1; k <= n; k++)
                        {
                            maxa = max (maxa, (A[k][1] + A[k][j]));
                        }
                    }
                    
                    for (k = 1; k < j; k++)
                    {
                        maxb = max (maxb, (A[i][k] + A[n][k]));
                    }
                    
                    A[i][j] = maxa + maxb;
                } else {
                    maxc = 0;
                    for (k = i; k < j; k++)
                    {
                        maxc = max (maxc, (A[i][k] + A[k+1][j]));
                    }
                    A[i][j] = maxc;
                }
            }
        }
        
        
        cout << A[1][n] << endl;
    }
    
    return 0;
}
