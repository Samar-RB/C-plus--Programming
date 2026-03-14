#ifndef HW3_GHOST_H
#define HW3_GHOST_H

#include "Enemies.h"

// Ghost enemy class
class Ghost : public Enemies{
public:
    Ghost(); 
    ~Ghost(){};
    virtual string getType() const; 
    virtual int calc_damage(int sum,int counter,char neg); 
};

#endif
