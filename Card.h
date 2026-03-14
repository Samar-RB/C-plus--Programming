#ifndef CARD_H
#define CARD_H

#include <iostream>
using namespace std;

// Represents a playing card with rank and suit
class Card {
private:
    char rank;
    char suit;

    int compare_val() const; // Compare value for sorting

public:
    Card(); // Default constructor
    Card(char r, char s); // Parameterized constructor
    ~Card() {};

    // Operator overloads for card comparison
    bool operator==(const Card &other) const;
    bool operator!=(const Card &other) const;
    bool operator<(const Card &other) const;
    bool operator<=(const Card &other) const;
    bool operator>(const Card &other) const;
    bool operator>=(const Card &other) const;

    Card &operator=(const Card &other); // Assignment operator

    char getsymbol() const; // Get suit symbol
    int getvalue() const;   // Get card value

    friend ostream &operator<<(ostream &os, const Card &c); // Output stream operator
};

#endif