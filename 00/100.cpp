#include <bits/stdc++.h>
using namespace std;

int main()
{
    int cycle_length[1000005];
    int sz = 1000001;

    memset(cycle_length, 0, sizeof(cycle_length));

    // fill powers of 2
    for (int e = 0; pow(2, e) < sz; e++) {
        cycle_length[(int) pow(2, e)] = e + 1;
    }

    int a, b;

	while(scanf("%d %d", &a, &b) != EOF) {
        int max_ele = 0;
        int start = min(a, b);
        int end = (a + b) - start;
        for (int i = start; i <= end; i++) {
            int cycles = 0;
            if (cycle_length[i] == 0) {
                unsigned int n = i;
                while (n > 1) {
                    if (n & 1) {
                        n = 3 * n + 1;
                        cycles++;
                    }
                    n = n >> 1;
                    cycles++;

                    if (n <= sz) {
                        if (cycle_length[n] != 0) {
                            cycles += cycle_length[n];
                            break;
                        }
                    }
                }
                cycle_length[i] = cycles;
            }
            max_ele = (cycle_length[i] > max_ele) ? cycle_length[i] : max_ele;
        }
        printf("%d %d %d\n", a, b, max_ele);
    }

    return 0;
}