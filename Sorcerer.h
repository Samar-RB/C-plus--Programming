#ifndef HW3_SORCERER_H
#define HW3_SORCERER_H

#include "Character.h"

// Sorcerer character class
class Sorcerer : public Characters{
public:
    Sorcerer(); 
    virtual int get_life_points()const; 
    virtual int get_cards_num()const;  
    ~Sorcerer(){};
    virtual string getType()const;  
    virtual void set_life_points(int sum,int damage,char neg,int count); 
};


#endif
