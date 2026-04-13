#include "KeyCard.h"
#include "Game.h"
#include "Player.h"
#include <iostream>

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
    if (!player.hasSuitInPlayArea(Chest))
    {
        return;
    }

    if (game.hasChestKeyBonusUsed())
    {
        return;
    }

    game.setChestKeyBonusUsed();

    int bonusCount = player.getPlayAreaSize();
    bool drewAnyCard = false;

    for (int i = 0; i < bonusCount; i++)
    {
        Card* bonusCard = game.drawFromDiscard();

        if (bonusCard == nullptr)
        {
            if (!drewAnyCard)
            {
                std::cout << "No cards in the discard pile. No bonus cards drawn." << std::endl;
            }
            else
            {
                std::cout << "No more cards in the discard pile." << std::endl;
            }

            return;
        }

        player.addToBank(bonusCard);
        drewAnyCard = true;

        std::cout << bonusCard->str() << " is added to the bank from the discard pile." << std::endl;
    }
}