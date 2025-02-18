#include "Board.h"

array<string, 40> property_location_index = {"Go", "Mediterranean Avenue", "Community Chest",
                                  "Baltic Avenue", "Income Tax", "Reading Railroad",
                                  "Oriental Avenue", "Chance", "Vermont Avenue", "Connecticut Avenue",
                                  "Jail / Just Visiting", "St. Charles Place", "Electric Company",
                                  "States Avenue", "Virginia Avenue", "Pennsylvania Railroad", "St. James Place",
                                  "Community Chest", "Tennessee Avenue", "New York Avenue", "Free Parking", 
                                  "Kentucky Avenue", "Chance", "Indiana Avenue", "Illinois Avenue", 
                                  "B. & O. Railroad", "Atlantic Avenue", "Ventnor Avenue", "Water Works",
                                  "Marvin Gardens", "Go To Jail", "Pacific Avenue", "North Carolina Avenue",
                                  "Community Chest", "Pennsylvania Avenue", "Short Line", "Chance", 
                                  "Park Place", "Luxury Tax", "Boardwalk"};

unsigned int DJB2(string locationName){
  unsigned int hash = 5381;
  for (size_t i=0; i < locationName.length(); i++) {
    char c = locationName[i]; 
    hash = ((hash << 5) + hash) + c;
  }
  return hash;
}

unsigned int ModuloBucketFunc(unsigned int hashcode, unsigned int cap){
  unsigned int b = hashcode % cap;
  return b;
}

Board::Board(){
}

Board::~Board(){
}

shared_ptr<hash_table> Board::InitTable(unsigned int cap){
  shared_ptr<hash_table> ret(new hash_table);
  ret->table = shared_ptr<htable>(new htable(cap));
  ret->capacity = cap;
  ret->hash_func = DJB2;
  ret->bucket_func = ModuloBucketFunc;
  fillBoard(ret);
  return ret;
}

shared_ptr<location> Board::InitNode(std::string locationName, unsigned int hashcode, int rent){
  shared_ptr<location> ret(new location);
  ret->locationName = locationName;
  ret->hashcode = hashcode;
  ret->rent = rent;
  return ret;
}

void Board::SetKVP(shared_ptr<hash_table> tbl, std::string locationName, int rent, int cost, string owned){
  shared_ptr<location> ret(new location);
  ret->locationName = locationName;
  ret->rent = rent;
  ret->cost = cost;
  ret->owned = "No";
  unsigned int hashcode = tbl->hash_func(locationName);
  unsigned int bucket_index = tbl->bucket_func(hashcode, tbl->capacity);

  unsigned int buckets_probed = 0;

  while (buckets_probed < tbl->capacity){
    //if the bucket is empty assign location to that bucket
    if (tbl -> table -> at(bucket_index) == NULL){
      tbl -> table -> at(bucket_index) = ret;
      return;
    }
    //increment bucket index to search next bucket
    bucket_index = (bucket_index + 1) % tbl->capacity;
    buckets_probed++;
  }
  return;
}

void Board::fillBoard(shared_ptr<hash_table> tbl){
  SetKVP(tbl, "Mediterranian Avenue", 10, 60, "No");
  SetKVP(tbl, "Baltic Avenue", 20, 60, "No");
  SetKVP(tbl, "Reading RR", 50, 200, "No");
  SetKVP(tbl, "Oriental Avenue", 12, 100, "No");
  SetKVP(tbl, "Vermont Avenue", 12, 100, "No");
  SetKVP(tbl, "Connecticut Avenue", 16, 120, "No");
  SetKVP(tbl, "St. Charles Place", 20, 140, "No");
  SetKVP(tbl, "Electric Company", 50, 150, "No");
  SetKVP(tbl, "States Avenue", 20, 140, "No");
  SetKVP(tbl, "Virginia Avenue", 24, 160, "No");
  SetKVP(tbl, "Pennsylvania RR", 50, 200, "No");
  SetKVP(tbl, "St. James Place", 28, 180, "No");
  SetKVP(tbl, "Tennessee Avenue", 28, 180,"No");
  SetKVP(tbl, "New York Avenue", 32, 200, "No");
  SetKVP(tbl, "Kentucky Avenue", 36, 220, "No");
  SetKVP(tbl, "Indiana Avenue", 36, 220, "No");
  SetKVP(tbl, "Illinois Avenue", 40, 240, "No");
  SetKVP(tbl, "B&O RR)", 50, 200, "No");
  SetKVP(tbl, "Atlantic Avenue", 44, 260, "No");
  SetKVP(tbl, "Ventnor Avenue", 44, 260, "No");
  SetKVP(tbl, "Water Works", 50, 150, "No");
  SetKVP(tbl, "Marvin Gardens", 48, 280, "No");
  SetKVP(tbl, "Pacific Avenue", 52, 300, "No");
  SetKVP(tbl, "North Carolina Avenue", 52, 300, "No");
  SetKVP(tbl, "Pennsylvania Avenue", 56, 320,"No");
  SetKVP(tbl, "Short Line", 50, 200, "No");
  SetKVP(tbl, "Park Place", 70, 350, "No");
  SetKVP(tbl, "Boardwalk", 100, 400, "No");
}

int Board::GetRent(shared_ptr<hash_table> tbl, std::string locationName){
  cout << locationName << endl;
  unsigned int hashcode = tbl->hash_func(locationName);
  unsigned int bucket_index = tbl->bucket_func(hashcode, tbl->capacity);
  shared_ptr<location> ret;
  ret = tbl -> table -> at(bucket_index);
  int rent = ret->rent;
  cout<< rent<< endl;
  return rent;
}
std::string Board::CheckIfOwned(shared_ptr<hash_table> tbl, std::string locationName){
  unsigned int hashcode = tbl->hash_func(locationName);
  unsigned int bucket_index = tbl->bucket_func(hashcode, tbl->capacity);
  shared_ptr<location> ret;
  ret = tbl -> table -> at(bucket_index);
  string owned = "";
  owned = ret->owned;
  return owned;
}

int Board::GetCost(shared_ptr<hash_table> tbl, string locationName){
  unsigned int hashcode = tbl->hash_func(locationName);
  unsigned int bucket_index = tbl->bucket_func(hashcode, tbl->capacity);
  shared_ptr<location> ret;
  ret = tbl -> table -> at(bucket_index);
  int cost = ret->cost;
  return cost;
}

string Board:: GetLocationName(int board_position){
  return property_location_index[board_position];
}

shared_ptr<location> Board::GetLocation(shared_ptr<hash_table> tbl, string locationName){
  unsigned int hashcode = tbl->hash_func(locationName);
  unsigned int bucket_index = tbl->bucket_func(hashcode, tbl->capacity);
  shared_ptr<location> ret;
  ret = tbl -> table -> at(bucket_index);
  while (ret != NULL) {
    if (ret->locationName == locationName) {
      return ret;
    }
  }
  return nullptr;
}

void Board::PrintTable(shared_ptr<hash_table> tbl){
    cout << "Monopoly:" << endl;
    for (unsigned int i=0; i < tbl->capacity; i++) {
        string owned = "";
        if(tbl->table->at(i)->owned == "No"){
            owned = "F";
        }
        else{
            owned = "T";
        }
        cout << "[" << i << "]    ";
        if (!tbl->table->at(i)) {
            cout << "<empty>" << endl;
        }
        else {
            cout << "\"" << tbl->table->at(i)->locationName << "\" = " << tbl->table->at(i)->rent << ", " << tbl->table->at(i)->cost << ", Owned: " << owned << endl;
        }
    }
}