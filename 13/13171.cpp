#include <bits/stdc++.h>
using namespace std;

int main() {
    int high = 0, counter = 0;
    bool firstX = true, line = false;
    char current;
    
    while (scanf("%c", &current) != EOF) {
        if (current == '\n') {
            high = max(counter - 1, high);
            printf("%d\n", high);
            high = 0;
            counter = 0;
            firstX = true;
            line = false;
        } else if (current == '.') {
            counter++;
            line = true;
        } else if (current == 'X') {
            if ((counter - 1) > high) {
                high = firstX ? (counter - 1) : max(high, (counter - 1) / 2);
            }
            firstX = false;
            line = true;
            counter = 0;
        }
    }
    if (line) {
        high = max(counter - 1, high);
        printf("%d\n", high);
    }

    return 0;
}
