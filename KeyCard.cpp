#include "KeyCard.h"

KeyCard::KeyCard(int value)
    : Card(Key, value)
{
}

std::string KeyCard::str() const
{
    return "Key(" + std::to_string(value) + ")";
}

void KeyCard::play(Game& game, Player& player)
{
}

void KeyCard::willAddToBank(Game& game, Player& player)
{
}