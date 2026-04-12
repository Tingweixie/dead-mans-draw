#ifndef CANNON_CARD_H
#define CANNON_CARD_H

#include "Card.h"

class CannonCard : public Card
{
public:
    CannonCard(int value);

    std::string str() const;
    void play(Game& game, Player& player);
};

#endif
