#include "MapCard.h"
#include "Game.h"
#include "Player.h"
#include <iostream>

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
    CardCollection drawnCards = game.drawManyFromDiscard(3);

    if (drawnCards.empty())
    {
        std::cout << "No cards in the discard pile. Play continues." << std::endl;
        return;
    }

    std::cout << "Choose one of these cards to play:" << std::endl;

    for (int i = 0; i < drawnCards.size(); i++)
    {
        std::cout << i + 1 << ". " << drawnCards[i]->str() << std::endl;
    }

    int choice = 0;
    bool validChoice = false;

    while (!validChoice)
    {
        std::cin >> choice;

        if (choice >= 1 && choice <= drawnCards.size())
        {
            validChoice = true;
        }
        else
        {
            std::cout << "Choose a valid card number." << std::endl;
        }
    }

    Card* chosenCard = drawnCards[choice - 1];

    for (int i = drawnCards.size() - 1; i >= 0; i--)
    {
        if (i != choice - 1)
        {
            game.addToDiscard(drawnCards[i]);
        }
    }

    std::cout << chosenCard->str() << " is played from the discard pile." << std::endl;

    if (player.playCard(chosenCard, game))
    {
        game.setBustFromAbility();
    }
}