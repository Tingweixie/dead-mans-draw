#include <iostream>
#include <cstdlib>
#include <ctime>
#include "GameTitle.h"
#include "Game.h"

int main()
{
    srand(time(0));

    std::cout << GAME_TITLE << std::endl;
    std::cout << "Starting Dead Man's Draw++!" << std::endl;

    Game game;
    game.startGame();

    return 0;
}
