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
    currentPlayerIndex = 0;
    roundNumber = 1;
    turnNumber = 1;

    initialisePlayers();
    createDeck();
    shuffleDeck();
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

void Game::createDeck()
{
    deck.createStandardDeck();
}

void Game::shuffleDeck()
{
    deck.shuffle();
}

void Game::playTurn()
{
}

void Game::switchPlayer()
{
    if (currentPlayerIndex == 0)
    {
        currentPlayerIndex = 1;
    }
    else
    {
        currentPlayerIndex = 0;
    }
}

Card* Game::drawFromDeck()
{
    return deck.drawTop();
}

void Game::addToDiscard(Card* card)
{
    discardPile.addCard(card);
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

bool Game::isGameOver() const
{
    if (deck.isEmpty())
    {
        return true;
    }

    if (turnNumber > maxTurns)
    {
        return true;
    }

    return false;
}

void Game::endGame() const
{
}

void Game::printFinalScores() const
{
}