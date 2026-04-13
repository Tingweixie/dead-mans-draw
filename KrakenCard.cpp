#include "KrakenCard.h"
#include "Game.h"
#include "Player.h"
#include <iostream>

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
    for (int i = 0; i < 3; i++)
    {
        Card* nextCard = game.drawFromDeck();

        if (nextCard == nullptr)
        {
            std::cout << "No cards left in the deck." << std::endl;
            game.setDeckEndedDuringAbility();
            return;
        }

        std::cout << player.getName() << " draws a " << nextCard->str() << std::endl;

        if (player.playCard(nextCard, game))
        {
            game.setBustFromAbility();
            return;
        }
    }
}