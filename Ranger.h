#ifndef HW3_RANGER_H
#define HW3_RANGER_H

#include "Character.h"

// Ranger character class
class Ranger : public Characters{
public:
    Ranger(); 
    virtual int get_life_points()const; 
    virtual int get_cards_num()const; 
    ~Ranger(){};
    virtual string getType()const;
    virtual void set_life_points(int sum,int damage,char neg,int count); 
};


#endif
