#include "MapCard.h"

MapCard::MapCard(int value)
    : Card(Map, value)
{
}

std::string MapCard::str() const
{
    return "Map(" + std::to_string(value) + ")";
}

void MapCard::play(Game& game, Player& player)
{
}