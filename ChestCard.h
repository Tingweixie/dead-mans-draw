#ifndef CHEST_CARD_H
#define CHEST_CARD_H

#include "Card.h"

class ChestCard : public Card
{
public:
    ChestCard(int value);

    std::string str() const;
    void play(Game& game, Player& player);
};

#endif
