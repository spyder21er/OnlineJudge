#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    char word[10];

    scanf("%d", &t);

    while (t--) {
        scanf("%s", word);
        if (strlen(word) == 5) {
            printf("3\n");
            continue;
        }
        int correct = (word[0] == 'o') + (word[1] == 'n') + (word[2] == 'e');
        if (correct > 1) {
            printf("1\n");
            continue;
        }
        printf("2\n");
    }
    
    return 0;
}