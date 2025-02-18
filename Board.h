#ifndef BOARD_H__
#define BOARD_H__

#include <string>
#include <memory>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

struct location{
    string locationName;
    int rent;
    unsigned int hashcode;
    string owned;
    int cost;
};


typedef vector<shared_ptr<location>> htable;

struct hash_table {
  unsigned int capacity;

  // table points to dynamic array of hash_node pointers
  shared_ptr<htable> table;
  unsigned int (*hash_func)(std::string);

  //currently in-use bucket indexing function
  unsigned int (*bucket_func)(unsigned int hashcode, unsigned int capacity); 
};

//hashes location name into an integer hash code
unsigned int DJB2(string locationName);

//returns hashe code % capacity
unsigned int ModuloBucketFunc(unsigned int hashcode, unsigned int cap);

class Board {
public:
  Board();
  ~Board();

  // Creates and initializes a hash_table structure and
  // returns a pointer to it. 
  shared_ptr<hash_table> InitTable(unsigned int cap);

  // Creates and initializes a hash_node that will occupy a
  // hash table bucket
  shared_ptr<location> InitNode(std::string locationName, unsigned int hashcode, int rent);

  // Establishes a mapping between the given key and value pair
  // in the provided hash table 
  void SetKVP(shared_ptr<hash_table> tbl, std::string locationName, int rent, int cost, string owned);

  void fillBoard(shared_ptr<hash_table> tbl);
  // Returns the value associated with the provded key in the table
  int GetRent(shared_ptr<hash_table> tbl, string locationName);

  std::string CheckIfOwned(shared_ptr<hash_table> tbl, std::string locationName);

  int GetCost(shared_ptr<hash_table> tbl, string locationName);

  string GetLocationName(int board_position);

  shared_ptr<location> GetLocation(shared_ptr<hash_table> tbl, string locationName);

  void PrintTable(shared_ptr<hash_table> tbl);
};

#endif  // BOARD_H__