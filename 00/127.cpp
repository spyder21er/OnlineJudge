#include <bits/stdc++.h>
using namespace std;

typedef pair<char, char> Card;
typedef stack <Card> Card_Stack;
typedef vector<Card_Stack> Pile;

Card make_card(const char *card_input)
{
    return make_pair(card_input[0], card_input[1]);
}

bool matches(Card a, Card b)
{
    return ((a.first == b.first) || (a.second == b.second));
}

void make_move(Pile & piles)
{
    bool can_still_move = true;
    while (can_still_move)
    {
        for (int i = 1; i < piles.size(); i++)
        {
            if (i > 2 && matches(piles[i - 3].top(), piles[i].top()))
            {
                piles[i - 3].push(piles[i].top());
            }
            else if (matches(piles[i - 1].top(), piles[i].top()))
            {
                piles[i - 1].push(piles[i].top());
            } else {
                // reached the end pile but din't find possible move
                if (i == (piles.size() - 1))
                    can_still_move = false;
                continue;
            }

            piles[i].pop();
            if (piles[i].empty())
            {
                piles.erase(piles.begin() + i);
                can_still_move = piles.size() > 1;
            }
            break; // Restart moving from leftmost pile
        }
    }
}

int main()
{
    char card_input[3];
    Card card;
    Pile piles;

    // get the initial card
    scanf("%s", &card_input);
    while (card_input[0] != '#')
    {
        vector<Card_Stack> piles;
        Card_Stack first_pile;
        first_pile.push(make_card(card_input));
        piles.push_back(first_pile);

        int remaining_cards = 51;

        while(remaining_cards--)
        {
            scanf("%s", &card_input);
            Card_Stack new_pile;
            new_pile.push(make_card(card_input));
            piles.push_back(new_pile);
            make_move(piles);
        }

        cout << piles.size();
        string s = (piles.size() == 1) ? " pile remaining: " : " piles remaining: ";
        cout << s;
        for(int i = 0; i < piles.size(); i++)
        {
            cout << piles[i].size();
            if(i+1 < piles.size())
                cout << " ";
        }
        cout << endl;

        scanf("%s", &card_input);
    }

    return 0;
}
