#ifndef MAP_CARD_H
#define MAP_CARD_H

#include "Card.h"

class MapCard : public Card
{
public:
    MapCard(int value);

    std::string str() const;
    void play(Game& game, Player& player);
};

#endif
