#include <bits/stdc++.h>
using namespace std;

int getsz(int n) {
    stringstream ss;
    ss << n; 
    string s = ss.str(); 
    return s.size();
}

int main() {
    // freopen ("12060.in", "r", stdin);
    
    int nm, dn, wl, tmp, mygcd;
    int ctr = 1;
    bool ltz = false;
    
    do {
        scanf("%d", &dn);
        if(!dn) break;
        nm = 0;
        wl = 0;
        for(int i = 0; i < dn; i++) {
            scanf("%d", &tmp);
            nm += tmp;
        }
        printf("Case %d:\n", ctr++);
        if(!nm) {
            printf("0\n");
            continue;
        }
        ltz = (nm < 0);
        nm = abs(nm);
        mygcd = __gcd(nm, dn);
        if(mygcd != 1) {
            nm /= mygcd;
            dn /= mygcd;
        }
        if(dn == 1) {
            if(ltz) printf("- %d\n", nm);
            else printf("%d\n", nm);
            continue;
        }
        int dnsz, tbsz;
        dnsz = getsz(dn);
        tbsz = dnsz + (ltz ? 2 : 0);
        if(nm > dn) {
            wl = nm / dn;
            nm = nm % dn;
            tbsz += getsz(wl);
            printf("%*d\n", tbsz, nm);
            if(ltz)
                printf("- %d%.*s\n", wl, dnsz, "----------");
            else
                printf("%d%.*s\n", wl, dnsz, "----------");
            printf("%*d\n", tbsz, dn);
        } else {
            printf("%*d\n", tbsz, nm);
            if(ltz)
                printf("- %.*s\n", dnsz, "----------");
            else
                printf("%.*s\n", dnsz, "----------");
            printf("%*d\n", tbsz, dn);
        }
    }while(true);
	return 0;
}