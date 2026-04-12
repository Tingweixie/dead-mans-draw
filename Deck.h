#ifndef DECK_H
#define DECK_H

#include "Card.h"

class Deck
{
private:
    CardCollection cards;

public:
    Deck();
    ~Deck();

    void createStandardDeck();
    void shuffle();

    Card* drawTop();
    Card* peekTop() const;

    bool isEmpty() const;
    int size() const;
};

#endif
