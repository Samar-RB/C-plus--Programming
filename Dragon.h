#ifndef HW3_DRAGON_H
#define HW3_DRAGON_H

#include "Enemies.h"

// Dragon enemy class
class Dragon : public Enemies{
public:
    Dragon();
    ~Dragon(){};
    virtual string getType() const; 
    virtual int calc_damage(int sum,int counter,char neg); 
};

#endif
