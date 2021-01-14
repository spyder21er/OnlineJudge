#include <bits/stdc++.h>
using namespace std;

int main() {
    string line, word;
    bool not_first_word;

    while (getline(cin, line)) {
        istringstream ss(line);
        not_first_word = false;
        while (ss >> word) {
            reverse(word.begin(), word.end());
            if (not_first_word) {
                printf(" ");
            }
            printf("%s", word.c_str());
            not_first_word = true;
        }
        printf("\n");
    }
    return 0;
}