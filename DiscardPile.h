#ifndef DISCARD_PILE_H
#define DISCARD_PILE_H

#include "Card.h"

class DiscardPile
{
private:
    CardCollection cards;

public:
    DiscardPile();
    ~DiscardPile();

    void clearCards();
    void addCard(Card* card);
    Card* drawTop();
    CardCollection drawMany(int count);

    bool isEmpty() const;
};

#endif
