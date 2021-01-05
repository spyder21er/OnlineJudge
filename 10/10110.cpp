#include <bits/stdc++.h>
using namespace std;

int main() {
    unsigned int n, root;

    while (scanf("%d", &n), n) {
        root = (int) sqrt(n);
        if (root * root == n) {
            printf("yes\n");
        } else {
            printf("no\n");
        }
    }
    return 0;
}