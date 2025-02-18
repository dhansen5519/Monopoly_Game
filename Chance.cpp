#include "Chance.h"
ChanceDeck::ChanceDeck(){

}
ChanceDeck::~ChanceDeck(){

}

shared_ptr<chanceCardDeck> ChanceDeck::InitDeck(){
    shared_ptr<chanceCardDeck> deck(new chanceCardDeck);
    deck->ChanceCardList.push("Advance to Boardwalk.");
    deck->ChanceCardList.push("Advance to Go (Collect $200).");
    deck->ChanceCardList.push("Advance to Illinois Avenue. If you pass Go, collect $200.");
    deck->ChanceCardList.push("Advance to St. Charles Place. If you pass Go, collect $200.");
    deck->ChanceCardList.push("Advance to the nearest Railroad. If unowned, you may buy it from the Bank. If owned, pay owner twice the rental to which they are otherwise entitled.");
    deck->ChanceCardList.push("Advance to the nearest Railroad. If unowned, you may buy it from the Bank. If owned, pay owner twice the rental to which they are otherwise entitled.");
    deck->ChanceCardList.push("Advance token to nearest Utility. If unowned, you may buy it from the Bank. If owned, throw dice and pay owner a total ten times amount thrown.");
    deck->ChanceCardList.push("Bank pays you dividend of $50.");
    deck->ChanceCardList.push("Get Out of Jail Free.");
    deck->ChanceCardList.push("Go Back 3 Spaces.");
    deck->ChanceCardList.push("Go to Jail. Go directly to Jail, do not pass Go, do not collect $200.");
    deck->ChanceCardList.push("Speeding fine $15.");
    deck->ChanceCardList.push("Take a trip to Reading Railroad. If you pass Go, collect $200.");
    deck->ChanceCardList.push("You have been elected Chairman of the Board. Pay each player $50.");
    deck->ChanceCardList.push("Your building loan matures. Collect $150");
    return deck;
}
string ChanceDeck::DrawChanceCard(shared_ptr<chanceCardDeck> deck){
    string ret = deck->ChanceCardList.front();
    deck->ChanceCardList.pop();
    cout << ret << endl;
    return ret;
}