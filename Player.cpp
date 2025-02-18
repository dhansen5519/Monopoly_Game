#include "Player.h"

Board newBoard;
shared_ptr<hash_table> tbl = newBoard.InitTable(28);

int property_count = 28;

Dice myDice;

Player myPlayer;

ChestDeck newChestDeck;
shared_ptr<cardDeck> chestdeck = newChestDeck.InitDeck();

ChanceDeck newChanceDeck;
shared_ptr<chanceCardDeck> deck = newChanceDeck.InitDeck();

Player::Player(){
}

Player::~Player(){
}

shared_ptr<player_info> Player::InitPlayer(string name){
    shared_ptr<player_info> ret(new player_info);
    ret->name = name;
    ret->board_position = 0;
    ret->money = 1500;
    ret->roll = 0;
    ret->properties = {};
    return ret;
}

string Player::getName(shared_ptr<player_info> player_info){
    return player_info->name;
}

int Player::getLocation(shared_ptr<player_info> player_info){
    return player_info->board_position;
}

void Player::setLocation(shared_ptr<player_info> player_info, int newLocation){
    player_info->board_position = newLocation;
}

int Player::getMoney(shared_ptr<player_info> player_info){
    return player_info->money;
}

void Player::setMoney(shared_ptr<player_info> player_info, int newAmount){
    player_info->money = newAmount;
}

int Player::buyProperty(shared_ptr<hash_table> tbl, shared_ptr<player_info> player_info, shared_ptr<location> newLocation){
    player_info->properties.push_back(newLocation);
    int rent = newBoard.GetRent(tbl, newLocation->locationName);
    int currMoney = player_info->money;
    player_info->money = currMoney - rent;
    newLocation->owned = player_info->name;
    cout << "Property has been purchased. Your new balance is " << player_info->money << endl;
    property_count--;
    return property_count;
}

string Player::getProperties(shared_ptr<player_info> player_info){
    for(long unsigned int i = 0; i< player_info->properties.size(); i++){
        cout << player_info->properties[i]->locationName << ", ";
    }
    return "";
}

void Player::IsSpecialSpace(int board_position, shared_ptr<player_info> player_info){
  if(board_position == 0){
    player_info->money += 200;
    cout << "Congrats you just recieved $200!" << endl;
    //return board_position;
  }
  else if(board_position == 2 || board_position == 17 || board_position == 33){
    cout << "You drew a comminity chest card!"<< endl;
    string card = newChestDeck.DrawChestCard(chestdeck);
    if( card == "Advance to Go (Collect $200)"){
      player_info->board_position = 0;
    }
    else if (card == "Bank error in your favor. Collect $200"){
      player_info->money += 200;
    }
    else if (card == "Doctor’s fee. Pay $50"){
      player_info->money -= 50;
    }
    else if (card == "From sale of stock you get $50"){
      player_info->money += 50;
    }
    else if (card == "Get Out of Jail Free"){
      //add functionality
    }
    else if (card == "Go to Jail. Go directly to jail, do not pass Go, do not collect $200"){
      player_info->board_position = 10;
    }
    else if(card == "Holiday fund matures. Receive $100"){
      player_info->money += 100;
    }
    else if (card == "Income tax refund. Collect $20"){
      player_info->money += 20;
    }
    else if (card == "It is your birthday. Collect $10 from every player"){
      //add functionality
    }
    else if (card == "Life insurance matures. Collect $100"){
      player_info->money += 100;
    }
    else if(card == "Pay hospital fees of $100"){
      player_info->money -= 100;
    }
    else if(card == "Pay school fees of $50"){
      player_info->money -= 50;
    }
    else if(card == "Receive $25 consultancy fee"){
      player_info->money += 25;
    }
    else if(card == "You are assessed for street repair. $40 per house. $115 per hotel"){
      //add functionality
    }
    else if(card == "You have won second prize in a beauty contest. Collect $10"){
      player_info->money += 10;
    }
    else if(card == "You inherit $100"){
      player_info->money += 100;
    }
    cout << card << endl;
    //return board_position;
  }
  else if(board_position == 4){
    player_info->money -= 200;
    cout << "You have been charged $200." << endl;
    //return board_position;
  }
  else if(board_position == 7 || board_position == 22 || board_position == 36){
    cout << "You drew a chance card!" << endl;
    string card = newChanceDeck.DrawChanceCard(deck);
    if( card == "Advance to Boardwalk."){
      player_info->board_position = 39;
    }
    else if (card == "Advance to Go (Collect $200)."){
      player_info->board_position = 0;
      player_info->money += 200;
    }
    else if (card == "Advance to Illinois Avenue. If you pass Go, collect $200."){
      if(player_info->board_position > 24){
        player_info->money += 200;
        player_info->board_position = 24;
      }
      else{
        player_info->board_position = 24;
      }
    }
    else if (card == "Advance to St. Charles Place. If you pass Go, collect $200."){
      if(player_info->board_position > 11){
        player_info->money += 200;
        player_info->board_position = 11;
      }
      else{
        player_info->board_position = 11;
      }
    }
    else if (card == "Advance to the nearest Railroad. If unowned, you may buy it from the Bank. If owned, pay wonder twice the rental to which they are otherwise entitled."){
      //add functionality
    }
    else if (card == "Advance to the nearest Railroad. If unowned, you may buy it from the Bank. If owned, pay wonder twice the rental to which they are otherwise entitled."){
      //add functionality
    }
    else if(card == "Advance token to nearest Utility. If unowned, you may buy it from the Bank. If owned, throw dice and pay owner a total ten times amount thrown."){
      //add functionality
    }
    else if (card == "Bank pays you dividend of $50."){
      player_info->money += 50;
    }
    else if (card == "Get Out of Jail Free."){
      //add functionality
    }
    else if (card == "Go Back 3 Spaces."){
      player_info->board_position -= 3;
      if(player_info->board_position > 40){
        int newPosition = player_info->board_position - 40; 
        player_info->board_position = newPosition;
      }
    }
    else if(card == "Go to Jail. Go directly to Jail, do not pass Go, do not collect $200."){
      player_info->board_position = 10;
    }
    else if(card == "Speeding fine $15."){
      player_info->money -= 15;
    }
    else if(card == "Take a trip to Reading Railroad. If you pass Go, collect $200."){
      player_info->board_position = 5;
    }
    else if(card == "You have been elected Chairman of the Board. Pay $50."){
      player_info->money -= 50;
    }
    else if(card == "Your building loan matures. Collect $150"){
      player_info->money += 150;
    }
    cout << card << endl;
    //return board_position;
  }
  else if(board_position == 12 || board_position == 28){
    player_info->money -=150;
    cout << "You have been charged 150"<< endl;
    //return board_position;
  }
  else if(board_position == 38){
    player_info->money -=150;
    cout << "You have been charged 150"<< endl;
    //return board_position;
  }
  else if(board_position == 20){
    cout << "Free parking" << endl;
    //return board_position;
  }
  else if(board_position == 30){
    board_position = 10;
    cout << "You have been sent to jail" << endl;
    //return board_position;
  }
  else{
    return;
  }
}

/*string movePlayer(shared_ptr<player_info> player_info){
    int newRoll = myDice.RollDice();
    cout << player_info->name << " you rolled " << newRoll << endl;
    player_info->board_position += newRoll;

    string propertyName = newBoard.GetLocationName(player_info->board_position);
    cout << "You are now on " << propertyName << endl;
    /*int cost = newBoard.GetCost(tbl, propertyName);
    int money = player_info->money;
    int newPropertyCount = 0;
    if(cost < money){
        if(newBoard.CheckIfOwned(tbl, propertyName) == "No"){
            string want_to_purchase;
            cout << "No on owns this property. The cost is " << cost << " dollars and you have" << money << ". Would you like to buy it?" << endl;
            cin >> want_to_purchase;
            if(want_to_purchase == "yes"){
                newPropertyCount = myPlayer.buyProperty(tbl, player_info, newBoard.GetLocation(tbl, propertyName));
                cout << "This property has been add to your list of own properties and your turn has now ended. Here are your current stats: " << endl;
                myPlayer.PrintPlayer(player_info);
                return newPropertyCount;
            }
            else{
                cout << "Your turn is now over. Here are your current stats: " << endl;
                myPlayer.PrintPlayer(player_info);
                return newPropertyCount;

            }
        }
    }
    return propertyName;//newPropertyCount;
}*/
void Player::PrintPlayer(shared_ptr<player_info> player_info){
    cout << "Player: " << getName(player_info) <<endl;
    cout << "Money: " << getMoney(player_info) << endl;
    cout << "Location: " << getLocation(player_info) << endl;
    cout << "Properties: " << getProperties(player_info);
}
