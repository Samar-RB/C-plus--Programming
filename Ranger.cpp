
#include "Ranger.h"

Ranger::Ranger() { lift_points = 50; cards_num = 7; }

int Ranger::get_life_points() const {
    return Characters::get_life_points();
}


int Ranger::get_cards_num() const {
    return Characters::get_cards_num();
}

string Ranger::getType() const {
    return "Ranger";
}

void Ranger::set_life_points(int sum,int damage,char neg,int count) {
    if(count==1 && neg!='H'){
        if (this->lift_points + sum > 50)
            this->lift_points = 50;
        else
            this->lift_points += sum;
        cout << "Player healed " << sum << " points of damage"<<'\n';

    }
    this->lift_points-=damage;
    if(this->lift_points <0)
    {
        this->lift_points=0;
    }
}

