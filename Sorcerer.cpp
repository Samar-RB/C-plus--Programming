
#include "Sorcerer.h"

Sorcerer::Sorcerer() { lift_points = 40; cards_num = 8; }

int Sorcerer::get_life_points() const {
    return Characters::get_life_points();
}


int Sorcerer::get_cards_num() const {
    return Characters::get_cards_num();
}
string Sorcerer::getType() const {
    return "Sorcerer";
}
void Sorcerer:: set_life_points(int sum,int damage,char neg,int count)
{
    if(count==1 && neg!='H')
    {
        if(this->lift_points+sum>40)
            this->lift_points=40;
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

