#include <bits/stdc++.h>
using namespace std;

int main() {
    string line;
    int word_count;
    while (getline(cin, line)) {
        word_count = 0;

        for (int i = 0; i < line.length(); i++) {
            if (isalpha(line[i])) {
                word_count++;
                while(isalpha(line[++i]));
            }
        }
        printf("%d\n", word_count);
    }
    return 0;
}