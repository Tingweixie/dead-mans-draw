#include "DiscardPile.h"

DiscardPile::DiscardPile()
{
}

void DiscardPile::addCard(Card* card)
{
    cards.push_back(card);
}

//Card* DiscardPile:
//{}

bool DiscardPile::isEmpty() const
{
    return cards.empty();
}

int DiscardPile::size() const
{
    return cards.size();
}