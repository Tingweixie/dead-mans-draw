#include "ChestCard.h"

ChestCard::ChestCard(int value)
    : Card(Chest, value)
{
}

std::string ChestCard::str() const
{
    return "Chest(" + std::to_string(value) + ")";
}

void ChestCard::play(Game& game, Player& player)
{
}

void ChestCard::willAddToBank(Game& game, Player& player)
{
}