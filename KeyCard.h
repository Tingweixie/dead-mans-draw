#ifndef KEY_CARD_H
#define KEY_CARD_H

#include "Card.h"

class KeyCard : public Card
{
public:
    KeyCard(int value);

    std::string str() const;
    void play(Game& game, Player& player);
    void willAddToBank(Game& game, Player& player);
};

#endif
