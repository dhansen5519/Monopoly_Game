#ifndef PLAYER_H__
#define PLAYER_H__

#include "Board.h"
#include "Dice.h"
#include "CommunityChest.h"
#include "Chance.h"
#include <string>
#include <memory>
#include <vector>
#include <iostream>

using namespace std;

struct player_info{
    string name;
    int board_position;
    int money;
    int roll;
    vector<shared_ptr<location>> properties;

};

class Player{
public:
    Player();
    ~Player();
    shared_ptr<player_info> InitPlayer(string name);
    string getName(shared_ptr<player_info> player_info);
    int getLocation(shared_ptr<player_info> player_info); // edit to return name of the space
    void setLocation(shared_ptr<player_info> player_info, int newLocation);
    int getMoney(shared_ptr<player_info> player_info);
    void setMoney(shared_ptr<player_info> player_info, int newAmount);
    int buyProperty(shared_ptr<hash_table> tbl, shared_ptr<player_info> player_info, shared_ptr<location> newProperty);
    void PrintPlayer(shared_ptr<player_info> player_info);
    string getProperties(shared_ptr<player_info> player_info);
    string movePlayer(shared_ptr<player_info> player_info);
    void IsSpecialSpace(int board_position, shared_ptr<player_info> player_info);
};

#endif  // PLAYER_H_