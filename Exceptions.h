#ifndef HW3_EXCEPTIONS_H
#define HW3_EXCEPTIONS_H

#include <iostream>
#include <exception>
using namespace std;

class Exceptions : public exception {
public:
    virtual void Handle() const = 0;
};

class deck_out_ex : public Exceptions {
public:
    deck_out_ex() {}
    void Handle() const override { cout << "Deck ran out\n"; }
};

class player_win : public Exceptions {
public:
    player_win() {}
    void Handle() const override { cout << "Player won\n"; }
};

class player_lose : public Exceptions {
public:
    player_lose() {}
    void Handle() const override { cout << "Player lost\n"; }
};

#endif
