#include "Deck.h"

Deck::Deck()
{
}

void Deck::createStandardDeck()
{
}

//void  Deck::shuffle( )
//{
//    ff


Card* Deck::drawTop()
{
    if (cards.empty())

    {
        return nullptr;
    }

    Card* topCard = cards.back();
    cards. pop_back();
    return topCard;
}

Card* Deck::peekTop() const
{
    if (cards.empty())
    {
        return nullptr;
    }
    return cards.back();
}

//bool Deck::isEmpty() const
//{
//    return cards.empty();
//}
//
//int Deck::size() const
//{
//    return cards.size();
//}