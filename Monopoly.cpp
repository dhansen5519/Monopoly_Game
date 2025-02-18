#include "Monopoly.h"

void Game::StartGame(){
    Board newBoard;
    shared_ptr<hash_table> tbl = newBoard.InitTable(28);
    int property_count = 28;
    vector<shared_ptr<player_info>> game_players;
    Player myPlayer;
    Dice myDice;
    
    long unsigned int player_count = 0;
    cout << "How many players are playing?"<< endl;
    cin >> player_count;
    for(long unsigned int i = 1; i <= player_count; i++){
        shared_ptr<player_info> newPlayer;
        string player_name;
        cout << "Enter player name: " << endl;
        cin >> player_name;
        newPlayer = myPlayer.InitPlayer(player_name);
        game_players.push_back(newPlayer);
        myPlayer.PrintPlayer(newPlayer);
        cout << endl;
    }
    while(property_count > 0){
        for(long unsigned int i = 0; i < game_players.size(); i++){
            shared_ptr<player_info> temp = game_players[i];
            string rollReady;
            cout << "" <<endl;
            cout<< "Enter Roll if you are ready for your turn or Exit to end game: " << endl;
            cin >> rollReady;
            if(rollReady == "Roll" || rollReady == "roll") {
                string propertyName = "";
                temp->roll = myDice.RollDice();
                cout << endl;
                cout << temp->name << " you rolled " << temp->roll << endl;
                temp->board_position += temp->roll;
                temp->roll = 0;
                if(temp->board_position > 40){
                    int newPosition = temp->board_position - 40;
                    temp->board_position = newPosition;
                }
                propertyName = newBoard.GetLocationName(temp->board_position);
                cout << "You are now on " << propertyName << endl;
                if(temp->board_position == 0 || temp->board_position == 2 || temp->board_position == 4 || temp->board_position == 7 || 
                    temp->board_position == 12 || temp->board_position == 17 || temp->board_position == 20 || temp->board_position == 22 ||
                    temp->board_position == 28 || temp->board_position == 30 || temp->board_position == 33 || temp->board_position == 36 || temp->board_position == 38){
                    myPlayer.IsSpecialSpace(temp->board_position, temp);
                    cout << endl;
                    cout << "Your turn is now over. Here are your current stats: " << endl;
                    myPlayer.PrintPlayer(temp);
                    cout << "" << endl;
                }      
                else{
                    int cost = newBoard.GetCost(tbl, propertyName);
                    int money = temp->money;
                    //string owned = newBoard.CheckIfOwned(tbl, propertyName);
                    if(cost < money){
                        string owned = "j";
                        if(owned == "No"){
                            string want_to_purchase;
                            cout << "No on owns this property. The cost is " << cost << " dollars and you have $" << money << ". Would you like to buy it?" << endl;
                            cin >> want_to_purchase;
                            if(want_to_purchase == "yes"){
                                property_count = myPlayer.buyProperty(tbl, temp, newBoard.GetLocation(tbl, propertyName));
                                cout << "This property has been add to your list of own properties and your turn has now ended. Here are your current stats: " << endl;
                                myPlayer.PrintPlayer(temp);
                                cout << "" << endl;
                            }
                        }
                        else{
                            int rent = newBoard.GetRent(tbl, propertyName);
                            for(long unsigned int i = 0; i < game_players.size(); i++){
                                if(game_players[i]->name == owned){
                                    game_players[i]->money += rent;
                                    cout << propertyName << " is owned by " << game_players[i]->name << ". You paid them $" << rent << endl;
                                }
                            }
                            temp->money -= rent;    
                        }
                    }
                    else{
                        cout << "Your turn is now over. Here are your current stats: " << endl;
                        myPlayer.PrintPlayer(temp);
                        cout << "" << endl;
                    }
                }
            }
            else if(rollReady == "Exit" || rollReady == "exit"){
                return;
            }
            else{
                cout << "You must enter Roll or Exit" << endl;
            }
        }
    }    
}