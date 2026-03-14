
#include "Character.h"

Characters::Characters() : lift_points(0), cards_num(0) {}

int Characters::get_life_points() const {
    return lift_points;
}

int Characters::get_cards_num() const {
    return cards_num;
}

string Characters::getType() const {
    return "Characters";
}

