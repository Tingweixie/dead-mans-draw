#ifndef MERMAID_CARD_H
#define MERMAID_CARD_H

#include "Card.h"

class MermaidCard : public Card
{
public:
    MermaidCard(int value);

    std::string str() const;
    void play(Game& game, Player& player);
};

#endif
