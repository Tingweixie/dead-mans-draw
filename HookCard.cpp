#include "HookCard.h"
#include "Game.h"
#include "Player.h"
#include <iostream>

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
    if (!player.hasCardsInBank())
    {
        std::cout << "          No cards in your bank. Play continues." << std::endl;
        return;
    }

    std::cout << "      Choose a suit toplay f rom your bank:" << std::endl;

    if (player.hasSuitInBank(Cannon))
    {
        std::cout << "Cannon" << std::endl;
    }

    if (player.hasSuitInBank(Chest))
    {
        std::cout << "Chest" << std::endl;
    }

    if (player.hasSuitInBank(Key))
    {
        std::cout << "Key" << std::endl;
    }

    if (player.hasSuitInBank(Sword))
    {
        std::cout << "Sword" << std::endl;
    }

    if (player.hasSuitInBank(Hook))
    {
        std::cout << "Hook" << std::endl;
    }

    if (player.hasSuitInBank(Oracle))
    {
        std::cout << "Oracle" << std::endl;
    }

    if (player.hasSuitInBank(Map))
    {
        std::cout << "Map" << std::endl;
    }

    if (player.hasSuitInBank(Mermaid))
    {
        std::cout << "Mermaid" << std::endl;
    }

    if (player.hasSuitInBank(Kraken))
    {
        std::cout << "Kraken" << std::endl;
    }

    std::string choice;
    CardType chosenType = Cannon;
    bool validChoice = false;

    while (!validChoice)
    {
        std::cin >> choice;

        if (choice == "Cannon" && player.hasSuitInBank(Cannon))
        {
            chosenType = Cannon;
            validChoice = true;
        }
        else if (choice == "Chest" && player.hasSuitInBank(Chest))
        {
            chosenType = Chest;
            validChoice = true;
        }
        else if (choice == "Key" && player.hasSuitInBank(Key))
        {
            chosenType = Key;
            validChoice = true;
        }
        else if (choice == "Sword" && player.hasSuitInBank(Sword))
        {
            chosenType = Sword;
            validChoice = true;
        }
        else if (choice == "Hook" && player.hasSuitInBank(Hook))
        {
            chosenType = Hook;
            validChoice = true;
        }
        else if (choice == "Oracle" && player.hasSuitInBank(Oracle))
        {
            chosenType = Oracle;
            validChoice = true;
        }
        else if (choice == "Map" && player.hasSuitInBank(Map))
        {
            chosenType = Map;
            validChoice = true;
        }
        else if (choice == "Mermaid" && player.hasSuitInBank(Mermaid))
        {
            chosenType = Mermaid;
            validChoice = true;
        }
        else if (choice == "Kraken" && player.hasSuitInBank(Kraken))
        {
            chosenType = Kraken;
            validChoice = true;
        }
        else
        {
            std::cout << "  Taht suit is not in your bank. Choose again." << std::endl;
        }
    }

    Card* chosenCard = player.removeHighestBankCard(chosenType);

    if (chosenCard != nullptr)
    {
        std::cout << player.getName() << " draws a " << chosenCard->str() << std::endl;

        if (player.playCard(chosenCard, game))
        {
            game.setBustFromAbility();
        }
    }
}