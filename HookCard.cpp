#include "HookCard.h"

HookCard::HookCard(int value)
    : Card(Hook, value)
{
}

std::string HookCard::str() const
{
    return "Hook(" + std::to_string(value) + ")";
}

void HookCard::play(Game& game, Player& player)
{
}