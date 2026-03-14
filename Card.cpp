#include "Card.h"

namespace {
int get_rank_val(char r) {
  switch (r) {
  case 'A':
    return 1;
  case '2':
    return 2;
  case '3':
    return 3;
  case '4':
    return 4;
  case '5':
    return 5;
  case '6':
    return 6;
  case '7':
    return 7;
  case '8':
    return 8;
  case '9':
    return 9;
  case 'T':
    return 10;
  case 'J':
    return 10;
  case 'Q':
    return 15;
  case 'K':
    return 20;
  default:
    return 0;
  }
}

int get_suit_val(char s) {
  switch (s) {
  case 'C':
    return 4;
  case 'S':
    return 3;
  case 'H':
    return 2;
  case 'D':
    return 1;
  default:
    return 0;
  }
}
}

Card::Card() : rank('0'), suit('0') {}

Card::Card(char r, char s) : rank(r), suit(s) {}

int Card::compare_val() const { return get_rank_val(rank); }

bool Card::operator==(const Card &other) const {
  const Card *p_other = &other;
  return (this->rank == p_other->rank && this->suit == p_other->suit);
}

bool Card::operator!=(const Card &other) const { return !(*this == other); }

bool Card::operator<(const Card &other) const {
  const Card *p_other = &other;

  int my_val = this->compare_val();
  int other_val = p_other->compare_val();

  if (my_val != other_val) {
    return my_val < other_val;
  }

  return get_suit_val(this->suit) < get_suit_val(p_other->suit);
}

bool Card::operator<=(const Card &other) const {
  return (*this < other) || (*this == other);
}

bool Card::operator>(const Card &other) const { return !(*this <= other); }

bool Card::operator>=(const Card &other) const { return !(*this < other); }

Card &Card::operator=(const Card &other) {
  if (this != &other) {
    this->rank = other.rank;
    this->suit = other.suit;
  }
  return *this;
}


ostream &operator<<(ostream &os, const Card &c) {
  Card default_card;
  if (c == default_card)
    return os;

  os << c.rank << c.suit;
  return os;
}

char Card::getsymbol() const {
  return this->suit;
}

int Card::getvalue() const {
  return this->compare_val();
}
