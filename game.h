#ifndef GAME_H
#define GAME_H

#include "board.h"

class Game
{
private:
    Board board;
    int turnNumber;
public:
    Game();
    Board getBoard();
    void Newgame();
};

#endif // GAME_H
