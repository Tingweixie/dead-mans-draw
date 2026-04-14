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
    std::string input = "";

    while (!validChoice)
    {
        std::cin >> input;

        if (input == "1")
        {
            choice = 1;
        }
        else if (input == "2")
        {
            choice = 2;
        }
        else if (input == "3")
        {
            choice = 3;
        }
        else
        {
            choice = 0;
        }

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