#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Card.h"

class Game;

class Player
{
private:
    std::string name;
    CardCollection playArea;
    CardCollection bank;

    void printCollection(const CardCollection& cards) const;

public:
    Player();
    ~Player();

    void setRandomName();
    std::string getName() const;

    bool playCard(Card* card, Game& game);
    bool hasSuitInPlayArea(CardType type) const;
    bool hasCardsInBank() const;
    bool hasSuitInBank(CardType type) const;
    void addToPlayArea(Card* card);

    void bankPlayArea(Game& game);
    void discardPlayArea(Game& game);

    void printPlayArea() const;
    void printBank() const;

    int getScore() const;
    Card* removeHighestBankCard(CardType type);
};

#endif
