#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A = 0, K = 1, Q = 2, J = 3, S = 4, H = 5, D = 6, C = 7, score;
    map< char, int > cards;
    map< char, vector< char > > royals;
    map< char, bool > stopped;
    char suits[] = {'S', 'H', 'D', 'C'};
    char card_input[3];

    while (scanf("%s", card_input) != EOF) {
        cards.clear();
        royals.clear();
        stopped.clear();

        cards[card_input[0]]++;
        cards[card_input[1]]++;
        royals[card_input[0]].push_back(card_input[1]);
        if (card_input[0] == 'A') stopped[card_input[1]] = true;
        for (int i = 0; i < 12; i++) {
            scanf("%s", card_input);
            cards[card_input[0]]++;
            cards[card_input[1]]++;
            royals[card_input[0]].push_back(card_input[1]);
            if (card_input[0] == 'A') stopped[card_input[1]] = true;
        }

        // Each ace counts 4 points. Each king counts 3 points. 
        // Each queen counts 2 points. Each jack counts one point.
        score = cards['A'] * 4 + cards['K'] * 3 + cards['Q'] * 2 + cards['J'];

        // Subtract a point for any king of a suit in which the hand holds no other cards.
        for (auto c : royals['K']) {
            if (cards[c] == 1) {
                score -= 1;
                break;
            }
            // stop if there are at least one other card
            if (cards[c] >= 2) stopped[c] = true;
        }

        // Subtract a point for any queen in a suit in which the hand 
        // holds only zero or one other cards.
        for (auto c : royals['Q']) {
            if (cards[c] >= 1 && cards[c] <= 2) {
                score -= 1;
                break;
            }
            // stop if there are at least two other cards
            if (cards[c] >= 3) stopped[c] = true;
        }

        // Subtract a point for any jack in a suit in which the hand 
        // holds only zero, one, or two other cards.
        for (auto c : royals['J']) {
            if (cards[c] <= 3 && cards[c] >= 1) {
                score -= 1;
                break;
            }
        }

        int stop_count = stopped['S'] + stopped['H'] + stopped['D'] + stopped['C'];
        if (score >= 16 && stop_count == 4) {
            printf("BID NO-TRUMP\n");
            continue;
        }

        char win;
        int most_card = 0;

        // Add a point for each suit in which the hand contains exactly two cards.
        for (auto suit : suits) {
            if (cards[suit] > most_card) {
                most_card = cards[suit];
                win = suit;
            }

            if (cards[suit] == 2)
                score += 1;
            // Add two points for each suit in which the hand contains exactly one card.
            else if (cards[suit] == 1)
                score += 2;
            // Add two points for each suit in which the hand contains no cards.
            else if (cards[suit] == 0)
                score += 2;
            
        }

        if (score < 14) 
            printf("PASS\n");
        else
            printf("BID %c\n", win);
    }

    return 0;
}