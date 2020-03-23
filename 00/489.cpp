#include <bits/stdc++.h>
using namespace std;

int main() {
    int round, count, hidden_letters;
    string word, guesses;
    unordered_map<char, int> letters;
    bitset<26> tried;

    while (true) {
        letters.clear();
        tried.reset();
        count = 0;
        scanf ("%d", &round);
        if (round == -1) break;
        printf("Round %d\n", round);
        cin >> word >> guesses;
        hidden_letters = word.length();
        for (int i = 0; i < word.length(); i++) {
            if (letters.find(word[i]) != letters.end()) {
                letters[word[i]] += 1;
            } else {
                letters[word[i]] = 1;
            }
        }

        for (int i = 0; i < guesses.length(); i++) {
            int iletter = (int) guesses[i] - 'a';
            auto pos = letters.find(guesses[i]);
            if (pos != letters.end()) {
                if (!tried.test(iletter)) {
                    hidden_letters -= pos->second;
                    if (hidden_letters == 0) {
                        printf("You win.\n");
                        break;
                    }
                }
            } else {
                if (!tried.test(iletter)) {
                    count++;
                    if (count == 7) {
                        printf("You lose.\n");
                        break;
                    }
                }
            }
            tried.set((int) guesses[i] - 'a');
        }
        if (hidden_letters > 0 && count < 7) {
            printf("You chickened out.\n");
        }
    }
    return 0;
}