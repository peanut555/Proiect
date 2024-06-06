#ifndef DECK_H_INCLUDED
#define DECK_H_INCLUDED
#include <cstring>
#include <random>
#include <time.h>
#include <algorithm>
using namespace std;
int cards[52];

string codeToCard (int card)
{
    int culoare = card/13;
    if (card == 52) culoare--;
    if (card == 39) culoare--;
    if (card == 26) culoare--;
    if (card == 13) culoare--;
    int valoare = card%13;

    string t;

    switch (culoare)
    {

            case 0 : {
                t += "Inima neagra ";
                break;
            }
            case 1 : {
                t += "Trifoi ";
                break;
            }
            case 2 : {
                t += "Inima rosie ";
                break;
            }
            case 3 : {
                t += "Romb ";
                break;
            }
    }

    switch (valoare)
    {
        case 0 : {
            t += "A";
            break;
        }
        case 10 : {
            t += "J";
            break;
        }
        case 11 : {
            t += "Q";
            break;
        }
        case 12 : {
            t += "K";
            break;
        }
        default : {
            t += to_string(valoare + 1);
            break;
        }
    }

    return t;
}

void initializer()
{
    for (int i = 0; i < 52; i++)
    {
        cards[i] = i;
    }
}

void shuffleDeck()
{
    random_shuffle(cards, cards + 52);
}

void showDeck ()
{
    for (int i = 0; i < 52; i++)
    {
        cout << codeToCard(cards[i]) << endl;
    }
}



#endif // DECK_H_INCLUDED
