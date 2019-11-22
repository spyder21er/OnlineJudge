#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen ("102.in","r", stdin);
    
    char perm[][4] = {"BCG", "BGC", "CBG", "CGB", "GBC", "GCB"};
    int btl[9];
    int mvs[6];
    
    while((scanf("%d", btl)) != EOF) {
        int sum = btl[0];
        for(int i = 1; i < 9; i++) {
            scanf("%d", btl + i);
            sum += btl[i];
        }
        mvs[0] = sum - (btl[0]+btl[5]+btl[7]);
        mvs[1] = sum - (btl[0]+btl[4]+btl[8]);
        mvs[2] = sum - (btl[2]+btl[3]+btl[7]);
        mvs[3] = sum - (btl[2]+btl[4]+btl[6]);
        mvs[4] = sum - (btl[1]+btl[3]+btl[8]);
        mvs[5] = sum - (btl[1]+btl[5]+btl[6]);
        int mnm = distance(mvs,(min_element(mvs, mvs+6)));
        printf("%s %d\n", perm[mnm], mvs[mnm]);
    }
    
	return 0;
}