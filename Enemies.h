#ifndef HW3_ENEMIES_H
#define HW3_ENEMIES_H

#include <iostream>
using namespace std;

#include "Card.h"

// Abstract base class for enemy types
class Enemies {
protected:
    int lift_points;
    int damage_points;

public:
    Enemies();  
    virtual int get_life_points() const;  // Get life points
    virtual int get_damage_points() const;  // Get damage points
    virtual ~Enemies(){};
    virtual string getType() const = 0;  // Get enemy type
    virtual int calc_damage(int sum, int counter, char neg) = 0;  // Calculate damage
    void set_health(int sum);  // Set health
};

#endif
