#include "Game.h"

Game::Game()
{
    players[0] = nullptr;
    players[1] = nullptr;
    currentPlayerIndex = 0;
    roundNumber = 1;
    turnNumber = 1;
    maxTurns = 20;
}

Game::~Game()
{
    delete players[0];
    delete players[1];
}

void Game::startGame()
{
    initialisePlayers();
}

void Game::initialisePlayers()
{
    if (players[0] == nullptr)
    {
        players[0] = new Player();
    }

    if (players[1] == nullptr)
    {
        players[1] = new Player();
    }

    players[0]->setRandomName();
    players[1]->setRandomName();
}

Player* Game::getCurrentPlayer() const
{
    return players[currentPlayerIndex];
}

Player* Game::getOtherPlayer() const
{
    if (currentPlayerIndex == 0)
    {
        return players[1];
    }

    return players[0];
}