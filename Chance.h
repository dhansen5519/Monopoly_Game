#ifndef CHANCE_H__
#define CHANCE_H__

#include <string>
#include <queue>
#include <memory>
#include <iostream>

using namespace std;

struct chanceCardDeck{
    queue<string> ChanceCardList;
};

class ChanceDeck{
public:
    ChanceDeck();
    ~ChanceDeck();
    shared_ptr<chanceCardDeck> InitDeck();
    string DrawChanceCard(shared_ptr<chanceCardDeck> deck);
};
#endif //CHANCE_H__