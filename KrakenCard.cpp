#include "KrakenCard.h"

KrakenCard::KrakenCard(int value)
    : Card(Kraken, value)
{
}

std::string KrakenCard::str() const
{
    return "Kraken(" + std::to_string(value) + ")";
}

void KrakenCard::play(Game& game, Player& player)
{
}