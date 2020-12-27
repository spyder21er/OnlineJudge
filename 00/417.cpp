#include <bits/stdc++.h>
using namespace std;

bool isValid(string word) {
    if (word.length() == 1) return true;
    char prev = word[0];
    for (int i = 1; i < word.length(); i++) {
        if (word[i] <= prev)
            return false;
        prev = word[i];
    }
    return true;
}

int indOf(char c) {
    return ((int) (c - 'a')) + 1;
}

int main() {
    int sums[][26] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1},
        {351, 300, 276, 253, 231, 210, 190, 171, 153, 136, 120, 105, 91, 78, 66, 55, 45, 36, 28, 21, 15, 10, 6, 3, 1},
        {2951, 2300, 2024, 1771, 1540, 1330, 1140, 969, 816, 680, 560, 455, 364, 286, 220, 165, 120, 84, 56, 35, 20, 10, 4, 1},
        {17901, 12650, 10626, 8855, 7315, 5985, 4845, 3876, 3060, 2380, 1820, 1365, 1001, 715, 495, 330, 210, 126, 70, 35, 15, 5, 1},
    };
    int sumlen[] = {0,0,26,351,2951,17901};
    string word;
    int ans, wordlength, previousLetter;
    while (cin >> word) {
        if (isValid(word)) {
            ans = 1;
            previousLetter = 0;
            wordlength = word.length();
            ans += sumlen[wordlength];
            for (int i = 0; i < wordlength; i++) {
                int currentLetter = indOf(word[i]);
                int diff = currentLetter - previousLetter;
                if (diff > 1) {
                    for (int j = previousLetter + 1; j < currentLetter; j++) {
                        ans += sums[wordlength-i][j];
                    }
                }
                previousLetter = currentLetter;
            }
            printf("%d\n", ans);
        } else {
            printf("0\n");
        }
    }
    return 0;
}