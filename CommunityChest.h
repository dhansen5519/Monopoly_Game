#ifndef COMMUNITYCHEST_H__
#define COMMUNITYCHEST_H__

#include <string>
#include <queue>
#include <memory>
#include <iostream>

using namespace std;

struct cardDeck{
    queue<string> ChestCardList;
};

class ChestDeck{
public:
    ChestDeck();
    ~ChestDeck();
    shared_ptr<cardDeck> InitDeck();
    string DrawChestCard(shared_ptr<cardDeck> deck);
};
#endif //COMMUNITYCHEST_H__