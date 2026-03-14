#include "Deck.h"
#include "Exceptions.h"
#include "Vector.h"
#include <stdexcept>


Deck::Deck() : deck_begin(nullptr), deck_end(nullptr), deck_limit(nullptr) {}

Deck::Deck(const Deck &other)
    : deck_begin(nullptr), deck_end(nullptr), deck_limit(nullptr) {
  int other_size = other.get_total();
  if (other_size > 0) {
    deck_begin = new Card[other_size];
    deck_end = deck_begin + other_size;
    deck_limit = deck_end;

    for (int i = 0; i < other_size; i++) {
      *(deck_begin + i) = other[i];
    }
  }
}

Deck::~Deck() {
  delete[] deck_begin;
}

Deck &Deck::operator=(const Deck &other) {
  if (this == &other)
    return *this;

  delete[] deck_begin;

  int other_size = other.get_total();
  if (other_size > 0) {
    deck_begin = new Card[other_size];
    deck_end = deck_begin + other_size;
    deck_limit = deck_end;

    for (int i = 0; i < other_size; i++) {
      *(deck_begin + i) = other[i];
    }
  } else {
    deck_begin = nullptr;
    deck_end = nullptr;
    deck_limit = nullptr;
  }
  return *this;
}

// Ensure enough capacity for new cards
void Deck::ensure_capacity(int added_amount) {
  int current_size = get_total();
  int current_cap = (deck_limit - deck_begin);
  int required = current_size + added_amount;

  if (required > current_cap) {
    int new_cap = (current_cap == 0) ? 1 : current_cap + (current_cap / 2) + 1;
    if (new_cap < required)
      new_cap = required;

    Card *new_begin = new Card[new_cap];

    for (int i = 0; i < current_size; i++) {
      *(new_begin + i) = *(deck_begin + i);
    }

    delete[] deck_begin;

    deck_begin = new_begin;
    deck_end = deck_begin + current_size;
    deck_limit = deck_begin + new_cap;
  }
}

// Add a card to the deck (insert at front)
Deck &Deck::operator+=(const Card &card) {
  ensure_capacity(1);

  Card *current = deck_end;

  while (current > deck_begin) {
    *current = *(current - 1);
    current--;
  }

  *deck_begin = card;
  deck_end++;

  return *this;
}

// Add all cards from another deck
Deck &Deck::operator+=(const Deck &other) {
  int other_count = other.get_total();

  for (int i = 0; i < other_count; i++) {
    *this += other[i];
  }
  return *this;
}

// Remove n cards from the deck (from end)
Deck &Deck::operator-=(int n) {
  if (n < 0) {
    return *this;
  }

  int current_size = get_total();
  if (n >= current_size) {
    deck_end = deck_begin;
  } else {
    deck_end -= n;
  }

  return *this;
}

// Remove a specific card from the deck
Deck &Deck::operator-=(const Card &card) {
  int current_size = get_total();
  
  for (int i = 0; i < current_size; i++) {
    if (*(deck_begin + i) == card) {
      for (int j = i; j < current_size - 1; j++) {
        *(deck_begin + j) = *(deck_begin + j + 1);
      }
      deck_end--;
      break;
    }
  }
  
  return *this;
}

// Access card by index (const)
Card Deck::operator[](int index) const {
  if (index < 0 || index >= get_total()) {
    throw std::out_of_range("Invalid index"); // Exception for invalid index
  }
  return *(deck_begin + index);
}

// Access card by index (non-const)
Card &Deck::operator[](int index) {
  if (index < 0 || index >= get_total()) {
    throw std::out_of_range("Invalid index"); // Exception for invalid index
  }
  return *(deck_begin + index);
}

// Get total number of cards
int Deck::get_total() const {
  return (int)(deck_end - deck_begin);
}

// Output deck to stream
ostream &operator<<(ostream &os, const Deck &deck) {
  os << "[";
  int size = deck.get_total();
  for (int i = 0; i < size; i++) {
    os << deck[i];
    if (i < size - 1)
      os << ",";
  }
  os << "]";
  return os;
}

// Get all cards as a Vector
Vector<Card> Deck::getmycards() const {
  Vector<Card> cards;
  int size = get_total();
  for (int i = 0; i < size; i++) {
    cards.push_back(*(deck_begin + i));
  }
  return cards;
}

// Set deck cards from a Vector
void Deck::setmycards(const Vector<Card> &cards) {
  delete[] deck_begin;
  
  int size = (int)cards.size();
  if (size > 0) {
    deck_begin = new Card[size];
    deck_end = deck_begin + size;
    deck_limit = deck_end;
    
    for (int i = 0; i < size; i++) {
      *(deck_begin + i) = cards[i];
    }
  } else {
    deck_begin = nullptr;
    deck_end = nullptr;
    deck_limit = nullptr;
  }
}

// Throw exception if hand ran out of cards
void Deck::IsRanOut(int max_hand, int current_hand) const {
  if (current_hand < max_hand) {
    throw deck_out_ex(); // Exception for deck out
  }
}

// Check if a card string is legal to play
bool Deck::Islegal(const string &card_str, const Deck &table) {
  if (card_str.length() < 2) {
    return false;
  }
  
  char rank = card_str[0];
  char suit = card_str[1];
  Card card(rank, suit);
  
  bool found_in_hand = false;
  int size = get_total();
  for (int i = 0; i < size; i++) {
    if (*(deck_begin + i) == card) {
      found_in_hand = true;
      break;
    }
  }
  
  if (!found_in_hand) {
    return false;
  }
  
  int table_size = table.get_total();
  for (int i = 0; i < table_size; i++) {
    if (table[i] == card) {
      return false;
    }
  }
  
  return true;
}