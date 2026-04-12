#ifndef KRAKEN_CARD_H
#define KRAKEN_CARD_H

#include "Card.h"

class KrakenCard : public Card
{
public:
    KrakenCard(int value);

    std::string str() const;
    void play(Game& game, Player& player);
};

#endif
