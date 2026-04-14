#include "OracleCard.h"
#include "Game.h"
#include <iostream>

OracleCard::OracleCard(int value)
    : Card(Oracle, value)
{
}

std::string OracleCard::str() const
{
    return "Oracle(" + std::to_string(value) + ")";
}

void OracleCard::play(Game& game, Player& player)
{
    Card* nextCard = game.peekFromDeck();

    if (nextCard == nullptr)
    {
        std::cout << "No cards left in the deck." << std::endl;
    }
    else
    {
        std::cout << "    The Oracle sees a " << nextCard->str() << std::endl;
    }
}