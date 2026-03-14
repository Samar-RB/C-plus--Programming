#ifndef HW3_CHARACTER_H
#define HW3_CHARACTER_H

#include <iostream>
using namespace std;

#include "Card.h"
#include "Enemies.h"

// Abstract base class for player characters
class Characters {
protected:
    int lift_points; // Variable to store life points
    int cards_num;   // Variable to store number of cards
public:
    Characters(); 
    virtual int get_life_points()const; 
    virtual int get_cards_num()const;   
    virtual ~Characters(){}; // Virtual destructor
    virtual string getType()const;   
    virtual void set_life_points(int sum,int damage,char neg,int count)=0; // Set life points
};

#endif
