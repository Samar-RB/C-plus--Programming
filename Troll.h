#ifndef HW3_TROLL_H
#define HW3_TROLL_H

#include "Enemies.h"

// Troll enemy class
class Troll : public Enemies{
public:
    Troll();
    ~Troll(){};
    virtual string getType() const; 
    virtual int calc_damage(int sum,int counter,char neg);
};

#endif
