#include <bits/stdc++.h>
using namespace std;

int main() {
    string a, b;
    int i, j;

    while (cin >> a >> b) {
        if (a.length() > b.length()) {
            printf("No\n");
            continue;
        }
        i = 0;
        for (j = 0; j < b.length() && i < a.length(); j++) {
            if (a[i] == b[j]) {
                i++;
            }
        }

        if (i == a.length()) {
            printf("Yes\n");
            continue;
        }
        printf("No\n");
    }
    return 0;
}