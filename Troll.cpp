#include "Troll.h"

Troll::Troll() { lift_points = 100; damage_points = 5; }

string Troll::getType() const {
    return "Troll";
}

int Troll::calc_damage(int sum, int counter, char neg) {
    int damage = this->damage_points;
    if(counter==1 && neg!='D')
    {

        damage = this->damage_points- sum;
        if(damage <0)
            damage=0;
    }
    return damage;
}
