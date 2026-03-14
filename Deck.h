#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include <iostream>
#include "Vector.h"
using namespace std;

class Deck {
private:
    Card *deck_begin;
    Card *deck_end;
    Card *deck_limit;
    void ensure_capacity(int added_amount);
public:
    Deck(); 
    Deck(const Deck &other); 
    ~Deck(); 
    Deck &operator=(const Deck &other); 
    Deck &operator+=(const Card &card); 
    Deck &operator+=(const Deck &other); 
    Deck &operator-=(int n); 
    Deck &operator-=(const Card &card); 
    Card operator[](int index) const; 
    Card &operator[](int index);      
    int get_total() const; 
    Vector<Card> getmycards() const; // Get all cards
    void setmycards(const Vector<Card> &cards); // Set cards
    void IsRanOut(int max_hand, int current_hand) const; // Check if hand ran out
    bool Islegal(const string &card_str, const Deck &table); // Check legality
    friend ostream &operator<<(ostream &os, const Deck &deck); // Output deck
};

#endif