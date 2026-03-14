#include "Enemies.h"

Enemies::Enemies() : lift_points(0), damage_points(0) {}

int Enemies::get_life_points() const {
    return lift_points;
}
int Enemies::get_damage_points()const
 {
    return damage_points;
 }

void Enemies::set_health(int sum) {
    this->lift_points-=sum;
    if(this->lift_points<0)
        this->lift_points =0;

}
