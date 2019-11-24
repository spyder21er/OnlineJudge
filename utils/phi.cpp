#include <bits/stdc++.h>
using namespace std;

#define MAX 2e6

unsigned long long phi[(int) MAX + 7];
unsigned long long depthphi[(int) MAX + 7];

/**
 * It took 0.902 secs to generate up to 1e7.
**/
void generatePhi()
{
    phi[1] = 1;
    depthphi[0] = 0;
    depthphi[1] = 0;
    for (int i = 2; i <= MAX; i++)
    {
        if (!phi[i])
        {
            phi[i] = i - 1;
            for (int j = (i << 1); j <= MAX; j += i)
            {
                if (!phi[j])
                    phi[j] = j;
                phi[j] = phi[j] * (i - 1) / i;
            }
        }
        depthphi[i] = 1 + depthphi[phi[i]];
    }
}

int main()
{
    generatePhi();

    for (int i = 1; i <= 2000000; i++)
        cout << depthphi[i] << ", ";
    cout << endl;
    return 0;
}