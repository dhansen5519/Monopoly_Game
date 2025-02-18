#include "CommunityChest.h"

ChestDeck::ChestDeck(){

}
ChestDeck::~ChestDeck(){

}

shared_ptr<cardDeck> ChestDeck::InitDeck(){
    shared_ptr<cardDeck> deck(new cardDeck);
    deck->ChestCardList.push("Advance to Go (Collect $200)");
    deck->ChestCardList.push("Bank error in your favor. Collect $200");
    deck->ChestCardList.push("Doctor’s fee. Pay $50");
    deck->ChestCardList.push("From sale of stock you get $50");
    deck->ChestCardList.push("Get Out of Jail Free");
    deck->ChestCardList.push("Go to Jail. Go directly to jail, do not pass Go, do not collect $200");
    deck->ChestCardList.push("Holiday fund matures. Receive $100");
    deck->ChestCardList.push("Income tax refund. Collect $20");
    deck->ChestCardList.push("It is your birthday. Collect $10 from every player");
    deck->ChestCardList.push("Life insurance matures. Collect $100");
    deck->ChestCardList.push("Pay hospital fees of $100");
    deck->ChestCardList.push("Pay school fees of $50");
    deck->ChestCardList.push("Receive $25 consultancy fee");
    deck->ChestCardList.push("You have won second prize in a beauty contest. Collect $10");
    deck->ChestCardList.push("You inherit $100");
    return deck;
}

string ChestDeck::DrawChestCard(shared_ptr<cardDeck> deck){
    string ret = deck->ChestCardList.front();
    deck->ChestCardList.pop();
    cout << ret << endl;
    return ret;
}