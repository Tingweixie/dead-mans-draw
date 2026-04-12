#include "DiscardPile.h"

DiscardPile::DiscardPile()
{
}

DiscardPile::~DiscardPile()
{
    while (!cards.empty())
    {
        delete cards.back();
        cards.pop_back();
    }
}
void DiscardPile::addCard(Card* card)
{
    cards.push_back(card);
}

Card* DiscardPile::drawTop()
{
    if (cards.empty())
    {
        return nullptr;
    }

    Card* topCard = cards.back();
    cards.pop_back();
    return topCard;
}

CardCollection DiscardPile::drawMany(int count)
{
    CardCollection drawnCards;

    while (count > 0 && !cards.empty())
    {
        drawnCards.push_back(cards.back());
        cards.pop_back();
        count--;
    }

    return drawnCards;
}

bool DiscardPile::isEmpty() const
{
    return cards.empty();
}

int DiscardPile::size() const
{
    return cards.size();
}