#include "Dragon.h"

Dragon::Dragon() { lift_points = 75; damage_points = 10; }

string Dragon::getType() const {
    return "Dragon";
}

int Dragon::calc_damage(int sum, int counter, char neg) {
    int damage = this->damage_points;
    if(counter==1 && neg!='D')
    {
        damage = this->damage_points- sum;
        if(damage <0)
            damage=0;
    }
    return damage;
}

