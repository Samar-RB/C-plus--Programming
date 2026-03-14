
#include "Ghost.h"

Ghost::Ghost() { lift_points = 50; damage_points = 15; }

string Ghost::getType() const {
    return "Ghost";
}

int Ghost::calc_damage(int sum, int counter, char neg) {
    int damage = this->damage_points;
    if(counter==1 && neg!='D')
    {

        damage = this->damage_points- sum;
        if(damage <0)
            damage=0;
    }
    return damage;
}
