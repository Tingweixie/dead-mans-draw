#include "Player.h"
#include "Game.h"

#include <cstdlib>
#include <iostream>

Player::Player()
{
    name = "";
}

void Player::setRandomName()
{
    std::string names[] = { "Sam", "Billy", "Jen", "Bob", "Sally",
                            "Joe", "Sue", "Sasha", "Tina", "Marge" };

    name = names[rand() % 10];
}

std::string Player::getName() const
{
    return name;
}

bool Player::hasSuitInPlayArea(CardType type) const
{

    for(int i = 0; i < playArea.size(); i++)
    {
        if (playArea[i]->type() == type)
        {
            return true;
        }
    }
    return false;
}

bool Player::playCard(Card* card, Game& game)
{
    if (hasSuitInPlayArea(card->type()))
    {

        addToPlayArea(card);
        return true;
 }

    addToPlayArea(card);
    card->play(game, *this);
    return false;
}


void Player::addToPlayArea(Card* card)
{
    playArea.push_back(card);
}

void Player::printCollection(const CardCollection& cards) const
{
    for (int suit = 0; suit < 9; suit++)
    {
        bool hasSuit = false;

        for (int i = 0; i < cards.size(); i++)
        {
            if (cards[i]->type() == suit)
            {
                hasSuit = true;
            }
        }

        if (hasSuit)
        {
            for (int value = 9; value >= 2; value--)
            {
                for (int i = 0; i < cards.size(); i++)
                {
                    if (cards[i]->type() == suit && cards[i]->getValue() == value)
                    {
                        std::cout << cards[i]->str() << " ";
                    }
                    }
            }

            std::cout << std::endl;
        }
           }
    }

void Player::printPlayArea() const
{
    printCollection(playArea);
}

void Player::printBank() const
{
    printCollection(bank);
    std::cout << "| Score: " << getScore() << std::endl;
}

void Player::bankPlayArea(Game& game)
{
    for (int i = 0; i < playArea.size(); i++)
    {
        playArea[i]->willAddToBank(game, *this);
    }

    while (!playArea.empty())
    {
        bank.push_back(playArea.back());
        playArea.pop_back();
    }
}

void Player::discardPlayArea(Game& game)
{
    while (!playArea.empty())
    {
        game.addToDiscard(playArea.back());
        playArea.pop_back();
    }
}

int Player::getScore() const
{
    int highestValues[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    int total = 0;

    for (int i = 0; i < bank.size(); i++)
    {
        int typeIndex = bank[i]->type();

        if (bank[i]->getValue() > highestValues[typeIndex])
        {
            highestValues[typeIndex] = bank[i]->getValue();
        }
    }

    for (int i = 0; i < 9; i++)
    {
        total = total + highestValues[i];
    }

    return total;
}

Card* Player::removeHighestBankCard(CardType type)
{
    int highestIndex = -1;

    for (int i = 0; i < bank.size(); i++)
    {
        if (bank[i]->type() == type)
        {
            if (highestIndex == -1 || bank[i]->getValue() > bank[highestIndex]->getValue())
            {
                highestIndex = i;
            }
        }
    }

    if (highestIndex == -1)
    {
        return nullptr;
    }

    Card* removedCard = bank[highestIndex];
    bank.erase(bank.begin() + highestIndex);

    return removedCard;
}
