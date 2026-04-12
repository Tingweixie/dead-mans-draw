#ifndef GAME_H
#define GAME_H

#include "Deck.h"
#include "DiscardPile.h"
#include "Player.h"

class Game
{
private:
    Deck deck;
    DiscardPile discardPile;
    Player* players[2];
    int currentPlayerIndex;
    int roundNumber;
    int turnNumber;
    int maxTurns;

public:
    Game();
    ~Game();

    void startGame();
    void initialisePlayers();

    Player* getCurrentPlayer() const;
    Player* getOtherPlayer() const;
};

#endif
