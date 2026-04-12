#ifndef ORACLE_CARD_H
#define ORACLE_CARD_H

#include "Card.h"

class OracleCard : public Card
{
public:
    OracleCard(int value);

    std::string str() const;
    void play(Game& game, Player& player);
};

#endif