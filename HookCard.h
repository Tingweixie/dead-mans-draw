#ifndef HOOK_CARD_H
#define HOOK_CARD_H

#include "Card.h"

class HookCard : public Card
{
public:
    HookCard(int value);

    std::string str() const;
    void play(Game& game, Player& player);
};

#endif
