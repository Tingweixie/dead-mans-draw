#include "Player.h"

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
}

void Player::printPlayArea() const
{
    printCollection(playArea);
}

void Player::printBank() const
{
    printCollection(bank);
}
