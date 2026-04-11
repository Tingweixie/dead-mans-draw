#ifndef CARD_H
#define CARD_H

#include <string>
#include <vector>

class Game;
class Player;

enum CardType
{
    Cannon,
    Chest,
    Key,
    Sword,
    Hook,
    Oracle,
    Map,
    Mermaid,
    Kraken
};

class Card
{
protected:
    CardType cardType;
    int value;

public:
    Card(CardType type, int value);
    virtual ~Card();

    const CardType& type() const;
    int getValue() const;

    virtual std::string str() const = 0;
    virtual void play(Game& game, Player& player) = 0;
    virtual void willAddToBank(Game& game, Player& player);
};

typedef std::vector<Card*> CardCollection;

#endif
