#include <bits/stdc++.h>
using namespace std;

int main() {
	long long aa, bb;
	while(scanf("%lld %lld", &aa, &bb)==2) {
		printf("%lld\n", max(aa,bb) - min(aa,bb));
	}
	return 0;
}