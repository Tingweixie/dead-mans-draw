#include "SwordCard.h"

SwordCard::SwordCard(int value)
    : Card(Sword, value)
{
}

std::string SwordCard::str() const
{
    return "Sword(" + std::to_string(value) + ")";
}

void SwordCard::play(Game& game, Player& player)
{
}