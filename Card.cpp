#include "Card.h"

Card::Card(CardType type, int value)
    : cardType(type), value(value)
{
}

Card::~Card()
{
}

const CardType& Card::type() const
{
    return cardType;
}

int Card::getValue() const
{
    return value;
}

void Card::willAddToBank(Game& game, Player& player)
{
}