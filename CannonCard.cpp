#include "CannonCard.h"

CannonCard::CannonCard(int value)
    : Card(Cannon, value)
{
}

std::string CannonCard::str() const
{
    return "Cannon(" + std::to_string(value) + ")";
}

void CannonCard::play(Game& game, Player& player)
{
}