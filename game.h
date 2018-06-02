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
    void newGame(int size, int lettuce, int cabbage, int grass, int helix, int slug, int worm);
    void nextTurn();
    void addOrganism(int x, int y, int index, string type);
    int getTurnNumber();
    void getBoardSize(int& rows, int& cols);
    string getFieldInfo(int x, int y);
    vector<int> getEncodedBoard();
    void getOrganismsNumber(int& lettuce, int& cabbage, int& grass, int& helix, int& slug, int& worm);
};

#endif // GAME_H
