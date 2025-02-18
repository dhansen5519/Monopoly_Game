#ifndef DICE_H__
#define DICE_H__

#include <memory>
#include <iostream>

using namespace std;

struct Die{
    int roll;
};

class Dice{
public:
    int RollDie();
    int RollDice();
private:
    int num_sides = 6;
};
#endif //DICE_H__