#include "ChestCard.h"
#include <iostream>

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
    std::cout << "    No immediate effect If the banked with a Key, draw ismany bonus cards from the discard pile as you moved into your bank." << std::endl;
}

void ChestCard::willAddToBank(Game& game, Player& player)
{
}