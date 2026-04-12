#ifndef SWORD_CARD_H
#define SWORD_CARD_H

#include "Card.h"

class SwordCard : public Card
{
public:
    SwordCard(int value);

    std::string str() const;
    void play(Game& game, Player& player);
};

#endif
