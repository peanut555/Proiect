#include <iostream>
#include "deck.h"

using namespace std;

int main()
{
    initializer();
    shuffleDeck();
int playerDecision;
    int i = 0;
playerDecision = 1;
    while (playerDecision)
    {int playerValue = 0, dealerValue = 0, secretDealerValue = 0;


    if (i >= 52)
    {
        i = 0;
        shuffleDeck();
    }

    playerValue = 0;

    cout << codeToCard(cards[i]) << endl;

    if (cards[i] % 13 == 0)
    {
        cout << "Pick value of ace: \n";
        cout << "1 or 11\n";
        cin >> playerDecision;
        if (playerDecision > 1)
            playerValue += 11;
        else
            playerValue += 1;
    }
    else
        if (cards[i] % 13 < 10)
            playerValue += cards[i]%13 + 1;
        else
            playerValue += 10;

    i++;
    secretDealerValue = 0;
    if (i >= 52)
    {
        i = 0;
        shuffleDeck();
    }

    secretDealerValue += cards[i];
    cout << "The dealer has: " << codeToCard(cards[i] ) << " and a hidden card\n";
    i++;
    if (i >= 52)
    {
        i = 0;
        shuffleDeck();
    }

    secretDealerValue += cards[i];
    i++;
    if (i >= 52)
    {
        i = 0;
        shuffleDeck();
    }


    cout << "Hit (1) or Stay (0)\n";
    cin >> playerDecision;


    while (playerDecision)
    {

    if (playerDecision == 1)
    {
        cout << codeToCard(cards[i]) << endl;
        i++;
        if (i >= 52)
    {
        i = 0;
        shuffleDeck();
    }
    cout << "Hit (1) or Stay (0)\n";
    cin >> playerDecision;

    }

    if (playerDecision == 0)
    {
        cout << "You have: " << playerValue << " and the dealer has " << secretDealerValue << endl;
        if (playerValue == 21)
            cout << "Blackjack!!\n";
        if (playerValue > 21)
            cout << "Bust!\n";
        if ((playerValue < secretDealerValue)&&(secretDealerValue < 21))
            cout << "Dealer wins!\n";
        else
            cout << "You win!\n";
    }
    }

    cout << "Continue? yes (1) no (0)";
    cin >> playerDecision;
    }
}
