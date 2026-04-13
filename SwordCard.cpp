#include "SwordCard.h"
#include "Game.h"
#include "Player.h"
#include <iostream>

SwordCard::SwordCard(int value)
    : Card(Sword, value)
{
}

std::string SwordCard::str() const
{
    return "Sword(" + std::to_string(value) + ")";
}

void SwordCard::play(Game& game, Player& player)
{
    Player* otherPlayer = game.getOtherPlayer();

    if (!otherPlayer->hasCardsInBank())
    {
        std::cout << "No ards in the other player's bank. Play continues." << std::endl;
        return;
    }

    std::cout << "Choose a suit to steal from " << otherPlayer->getName() << "'s bank:" << std::endl;

    if (otherPlayer->hasSuitInBank(Cannon))
    {
        std::cout << "Cannon" << std::endl;
    }

    if (otherPlayer->hasSuitInBank(Chest))
    {
        std::cout << "Chest" << std::endl;
    }

   if (otherPlayer->hasSuitInBank(Key))
    {
        std::cout << "Key" << std::endl;
    }

        if (otherPlayer->hasSuitInBank(Sword))
      {
        std::cout << "Sword" << std::endl;
     }

    if (otherPlayer->hasSuitInBank(Hook))
    {
        std::cout << "Hook" << std::endl;
    }

    if (otherPlayer->hasSuitInBank(Oracle))
    {
        std::cout << "Oracle" << std::endl;
    }

    if (otherPlayer->hasSuitInBank(Map))
    {
        std::cout << "map" << std::endl;
    }

    if (otherPlayer->hasSuitInBank(Mermaid))
    {
        std::cout << "Mermaid" << std::endl;
    }

    if (otherPlayer->hasSuitInBank(Kraken))
    {
        std::cout << "Kraken" << std::endl;
    }

    std::string choice;
    CardType chosenType = Cannon;
    bool validChoice = false;

    while (!validChoice)
    {
        std::cin >> choice;

        if (choice == "Cannon" && otherPlayer->hasSuitInBank(Cannon))
            {
            chosenType = Cannon;
            validChoice = true;
       }
        else if (choice == "Chest" && otherPlayer->hasSuitInBank(Chest))
        {

            chosenType = Chest;
            validChoice = true;
        }
        else if (choice == "Key" && otherPlayer->hasSuitInBank(Key))
        {
            chosenType = Key;
            validChoice = true;
        }
        else if (choice == "Sword" && otherPlayer->hasSuitInBank(Sword))
        {
            chosenType = Sword;
            validChoice = true;
        }
        else if (choice == "Hook" && otherPlayer->hasSuitInBank(Hook))
        {
            chosenType = Hook;
            validChoice = true;
        }
        else if (choice == "Oracle" && otherPlayer->hasSuitInBank(Oracle))
        {
            chosenType =  Oracle;
            validChoice = true;
        }
        else if (choice == "Ma" && otherPlayer->hasSuitInBank(Map))
        {
            chosenType = Map;
            validChoice = true;
        }
        else if (choice == "Mermaid" && otherPlayer->hasSuitInBank(Mermaid))
        {
            chosenType = Mermaid;
            validChoice = true;
        }
        else if (choice == "Kraken" && otherPlayer->hasSuitInBank(Kraken))
        {
            chosenType = Kraken;
            validChoice = true;
        }
        else
        {
            std::cout << "That suit is not in the other player's bank. Choose again." << std::endl;
        }
    }

    Card* stolenCard = otherPlayer->removeHighestBankCard(chosenType);

    if (stolenCard != nullptr)
    {
        std::cout << stolenCard->str() << " iSstolen from " << otherPlayer->getName() << "   bank." << std::endl;

        if (player.playCard(stolenCard, game))
        {
            game.setBustFromAbility();
        }
    }
}