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
