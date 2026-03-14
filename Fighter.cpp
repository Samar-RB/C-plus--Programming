
#include "Fighter.h"

Fighter::Fighter() { lift_points = 60; cards_num = 6; }

int Fighter::get_life_points() const {
    return Characters::get_life_points();
}


int Fighter::get_cards_num() const {
    return Characters::get_cards_num();
}

string Fighter::getType() const {
    return "Fighter";
}
void Fighter:: set_life_points(int sum,int damage,char neg,int count)
{
    if(count==1 && neg!='H')
    {
        if(this->lift_points+sum>60)
            this->lift_points=60;
        else
            this->lift_points+=sum;
        cout << "Player healed " << sum << " points of damage"<<'\n';
    }
    this->lift_points-=damage;
    if(this->lift_points <0)
    {
        this->lift_points=0;
    }
}
