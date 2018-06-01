#ifndef GAME_H
#define GAME_H

#include <string>

#include "board.h"

class Game
{
private:
    Board board;
    int turnNumber = 0;

public:
    Game();
    Game(int size, int lettuce, int cabbage, int grass, int helix, int slug, int worm);
    void newGame();
    void nextTurn();
    void addOrganism(int x, int y, string type);
    int getTurnBumber();
    Board getBoard();

};

#endif // GAME_H
