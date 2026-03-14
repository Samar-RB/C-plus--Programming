#ifndef HW3_FIGHTER_H
#define HW3_FIGHTER_H


#include "Character.h"

// Fighter character class
class Fighter : public Characters{
public:
    Fighter(); 
    virtual int get_life_points()const; 
    virtual int get_cards_num()const;   
    ~Fighter(){};
    virtual string getType()const;      
    virtual void set_life_points(int sum,int damage,char neg,int count); 
};


#endif
