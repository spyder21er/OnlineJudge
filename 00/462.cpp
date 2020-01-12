#include <bits/stdc++.h>
using namespace std;

bool is_royal(char c) {
    return (c == 'A' || c == 'K' || c == 'Q' || c == 'J');
}

int main()
{
    int score;
    map< char, int > suit_count;
    map< char, vector< char > > royals;
    map< char, bool > stopped;
    char suits[] = {'S', 'H', 'D', 'C'};
    char card_input[3];

    while (scanf("%s", &card_input) != EOF) {
        suit_count.clear();
        royals.clear();
        stopped.clear();
        score = 0;

        if (is_royal(card_input[0])) { 
            // add card suit if royal
            royals[card_input[0]].push_back(card_input[1]);
        }
        suit_count[card_input[1]]++; // add card suit count

        // if Ace stop the suit
        if (card_input[0] == 'A') stopped[card_input[1]] = true;

        // do the same fo the remaining cards
        for (int i = 0; i < 12; i++) {
            scanf("%s", card_input);
            if (is_royal(card_input[0])) { 
                royals[card_input[0]].push_back(card_input[1]);
            }
            suit_count[card_input[1]]++; // add card suit count
            if (card_input[0] == 'A') stopped[card_input[1]] = true;
        }

        // Each ace counts 4 points. Each king counts 3 points. 
        // Each queen counts 2 points. Each jack counts one point.
        score = royals['A'].size() * 4 + royals['K'].size() * 3 + royals['Q'].size() * 2 + royals['J'].size();

        // Subtract a point for any king of a suit in which the hand holds no other suit_count.
        for (auto c : royals['K']) {
            if (suit_count[c] == 1) {
                score -= 1;
            }
            // stop if there are at least one other card
            if (suit_count[c] >= 2) stopped[c] = true;
        }

        // Subtract a point for any queen in a suit in which the hand 
        // holds only zero or one other suit_count.
        for (auto c : royals['Q']) {
            if (suit_count[c] >= 1 && suit_count[c] <= 2) {
                score -= 1;
            }
            // stop if there are at least two other suit_count
            if (suit_count[c] >= 3) stopped[c] = true;
        }

        // Subtract a point for any jack in a suit in which the hand 
        // holds only zero, one, or two other suit_count.
        for (auto c : royals['J']) {
            if (suit_count[c] <= 3 && suit_count[c] >= 1) {
                score -= 1;
            }
        }

        int stop_count = stopped['S'] + stopped['H'] + stopped['D'] + stopped['C'];
        if (score >= 16 && stop_count == 4) {
            printf("BID NO-TRUMP\n");
            continue;
        }

        char win;
        int most_card = 0;

        for (auto suit : suits) {
            if (suit_count[suit] > most_card) {
                most_card = suit_count[suit];
                win = suit;
            }

            // Add a point for each suit in which the hand contains exactly two suit_count.
            if (suit_count[suit] == 2)
                score += 1;
            // Add two points for each suit in which the hand contains exactly one card.
            else if (suit_count[suit] == 1)
                score += 2;
            // Add two points for each suit in which the hand contains no suit_count.
            else if (suit_count[suit] == 0)
                score += 2;
            
        }

        if (score < 14) 
            printf("PASS\n");
        else
            printf("BID %c\n", win);
    }

    return 0;
}