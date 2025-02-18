#include "Dice.h"

int Dice::RollDie(){
    shared_ptr<Die> Die1(new Die);
    Die1->roll = 0;
    Die1->roll = rand() % num_sides + 1;
    return Die1->roll;
}

int Dice::RollDice(){
    shared_ptr<Die> die1(new Die);
    shared_ptr<Die> die2(new Die);
    die1->roll = RollDie();
    die2->roll = RollDie();
    return die1->roll + die2->roll;   
}